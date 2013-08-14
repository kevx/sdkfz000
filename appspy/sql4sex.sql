add file /home/beitang.xz/appspy/myreplace.py;
create temporary function idcard_info  AS 'com.taobao.hive.udf.UDFIDCard';

ALTER TABLE s_bmw_users ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/hive/s_bmw_users/pt=xxxxxxxx000000';

drop table t_swappspy_sex;

create table if not exists t_swappspy_sex(uid string, sex int, appdata string) stored as sequencefile;

insert overwrite table t_swappspy_sex
select swa.userid, idcard_info(bu.id_card_number, 'gender') as sex, swa.appdata
from t_swappspy_sampling swa join s_bmw_users bu on (
    cast(swa.userid as bigint) = cast(bu.user_id as bigint)
    and  bu.pt='xxxxxxxx000000'
);

drop table t_swappspy_sex_male;
drop table t_swappspy_sex_female;

create table if not exists t_swappspy_sex_male(
    pkg string, cnt int
) stored as sequencefile;

create table if not exists t_swappspy_sex_female(
    pkg string, cnt int
) stored as sequencefile;

insert overwrite table t_swappspy_sex_male
select vt.pkg, count(1) as cnt from (
    select transform(vpkg) using 'myreplace.py' as pkg
    from t_swappspy_sex t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg where t.sex = 1
) vt where trim(vt.pkg) != ''  group by vt.pkg;

insert overwrite table t_swappspy_sex_female
select vt.pkg, count(1) as cnt from (
    select transform(vpkg) using 'myreplace.py' as pkg
    from t_swappspy_sex t LATERAL VIEW explode(
        split(get_json_object(t.appdata, '$.apps[*].packageName'), ',')
    ) vvt AS vpkg where t.sex = 2
) vt where trim(vt.pkg) != ''  group by vt.pkg;