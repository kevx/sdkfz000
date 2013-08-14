ALTER TABLE s_software_download_log ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/dw/stb/xxxxxxxx/software_download_log';

ALTER TABLE s_software_item ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/dw/stb/xxxxxxxx/software_item';

ALTER TABLE r_bmw_users_mv ADD IF NOT EXISTS PARTITION (pt='xxxxxxxx000000') LOCATION 'hdfs://hdpnn:9000/group/taobao/taobao/hive/r_bmw_users_mv/pt=xxxxxxxx000000';

CREATE TEMPORARY FUNCTION date_format AS 'com.taobao.hive.udf.UDFDateFormat';

drop table t_swapptj_user;

create table if not exists t_swapptj_user (app_id int, user_id bigint, gender smallint, age int)
stored as sequencefile;

insert overwrite table t_swapptj_user
select sdl.app_id, sdl.user_id, bum.gender, bum.age
from s_software_download_log sdl
join r_bmw_users_mv bum on (
    date_format(sdl.gmt_create, 'yyyyMMdd') = 'xxxxxxxx'  and
    sdl.user_id = bum.user_id and
    sdl.pt = 'xxxxxxxx000000' and
    bum.pt = 'xxxxxxxx000000'
);

drop table t_swapptj_app18_24_m;
drop table t_swapptj_app18_24_f;
drop table t_swapptj_app24_35_m;
drop table t_swapptj_app24_35_f;
drop table t_swapptj_app35_45_m;
drop table t_swapptj_app35_45_f;

create table if not exists t_swapptj_app18_24_m(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;
create table if not exists t_swapptj_app18_24_f(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;
create table if not exists t_swapptj_app24_35_m(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;
create table if not exists t_swapptj_app24_35_f(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;
create table if not exists t_swapptj_app35_45_m(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;
create table if not exists t_swapptj_app35_45_f(app_id int, app_name string, package_name string, cnt int) stored as sequencefile;

---------------------------------------------------
--Male_[18, 24)
insert overwrite table t_swapptj_app18_24_m
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 1 and age >= 18 and age < 24
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);

--Female_[18, 24)
insert overwrite table t_swapptj_app18_24_f
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 2 and age >= 18 and age < 24
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);
-----------------------------------------------------
--Male_[24, 35)
insert overwrite table t_swapptj_app24_35_m
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 1 and age >= 24 and age < 35
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);

--FeMale_[24, 35)
insert overwrite table t_swapptj_app24_35_f
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 2 and age >= 24 and age < 35
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);

------------------------------------------------------
--Male_[35, 45)
insert overwrite table t_swapptj_app35_45_m
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 1 and age >= 35 and age < 45
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);

--FeMale_[35, 45)
insert overwrite table t_swapptj_app35_45_f
select t.app_id, si.app_name, si.package_name, t.cnt
from (
    select app_id, count(1) as cnt from t_swapptj_user
    where gender = 2 and age >= 35 and age < 45
    group by app_id
) t join  s_software_item si on (
    si.pt = 'xxxxxxxx000000' and
    si.app_id = t.app_id
);

