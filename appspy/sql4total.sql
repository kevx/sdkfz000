add file /home/beitang.xz/appspy/myreplace.py;

ALTER TABLE sw_appspy ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx') 
LOCATION 'hdfs://hdpnn:9000/group/trade/input/log/TimeTunnel2/softwarecenterappspy/xxxxxxxx';

drop table t_swappspy_total;
drop table t_swappspy_sampling;

create table if not exists t_swappspy_total(
    pkg string, cnt int
) stored as sequencefile;

create table if not exists t_swappspy_sampling (
    userid string, appdata string, vindx int
) stored as sequencefile;

insert overwrite table t_swappspy_sampling
select vt.userid, vt.appdata, vt.vidx from ( 
    select userid, appdata, cast(rand() * 100000 as int) as vidx 
    from sw_appspy where pt='xxxxxxxx' 
) vt order by vt.vidx limit 5000;

insert overwrite table t_swappspy_total
select vt.pkg, count(1) as cnt from (
    select transform(vpkg) using 'myreplace.py' as pkg
    from t_swappspy_sampling t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg
) vt where trim(vt.pkg) != ''  group by vt.pkg;
