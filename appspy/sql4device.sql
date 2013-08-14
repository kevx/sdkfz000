add file /home/beitang.xz/appspy/device2class.py;
add file /home/beitang.xz/appspy/myreplace.py;

ALTER TABLE s_bmw_users ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/hive/s_bmw_users/pt=xxxxxxxx000000';

ALTER TABLE s_software_device ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/dw/stb/xxxxxxxx/software_device';

drop table t_swappspy_device;

create table if not exists t_swappspy_device(
    uid string, appdata string, devcls tinyint
) stored as sequencefile;

insert overwrite table t_swappspy_device
select transform(s.user_id, swa.appdata, s.model) using 'device2class.py' as (uid, appdata, devcls) from s_software_device s join (
    select max(cast(id as bigint)) as maxid from s_software_device
    where  pt='xxxxxxxx000000' group by user_id
) vt on (
    cast(s.id as bigint) = vt.maxid and
    s.pt='xxxxxxxx000000' 
) join t_swappspy_sampling swa on (
    cast(swa.userid as bigint) = cast(s.user_id as bigint)
);

drop table t_swappspy_device1;
drop table t_swappspy_device2;
drop table t_swappspy_device3;

create table if not exists t_swappspy_device1(
    pkg string, cnt int
) stored as sequencefile;

create table if not exists t_swappspy_device2(
    pkg string, cnt int
) stored as sequencefile;

create table if not exists t_swappspy_device3(
    pkg string, cnt int
) stored as sequencefile;

insert overwrite table t_swappspy_device1
select vt.pkg, count(1) as cnt from (
    SELECT transform(vpkg) using 'myreplace.py' as pkg
    FROM t_swappspy_device t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg where t.devcls = 1
) vt where trim(vt.pkg) != ''  group by vt.pkg;

insert overwrite table t_swappspy_device2
select vt.pkg, count(1) as cnt from (
    SELECT transform(vpkg) using 'myreplace.py' as pkg
    FROM t_swappspy_device t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg where t.devcls = 2
) vt where trim(vt.pkg) != ''  group by vt.pkg;


insert overwrite table t_swappspy_device3
select vt.pkg, count(1) as cnt from (
    SELECT transform(vpkg) using 'myreplace.py' as pkg
    FROM t_swappspy_device t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg where t.devcls = 3
) vt where trim(vt.pkg) != ''  group by vt.pkg;

