#!/bin/sh

PATH=/bin:/usr/bin:$PATH
source /etc/profile
source /home/beitang.xz/.bashrc
export LANG=zh_CN.GBK
localDir=`dirname "$0"`
localDir=`cd "$localDir"; pwd`

host='softwarecenter143191.cm6'
hostx='172.23.227.74'

gday=`date --date="1 days ago" +%Y%m%d`
mkdir $localDir/data/$gday

echo ">>>day is :$gday"
echo ">>>local data path: $localDir/data"

rm -f $localDir/sql4*.t

cp $localDir/sql4sex.sql $localDir/sql4sex.t
cp $localDir/sql4device.sql $localDir/sql4device.t
cp $localDir/sql4total.sql $localDir/sql4total.t
cp $localDir/sql4mix.sql $localDir/sql4mix.t

cp $localDir/sql4tuijian.sql $localDir/sql4tuijian.t

sed -i "s/xxxxxxxx/$gday/g" $localDir/sql4*.t

echo ">>>Start running App Spy"
hive -f $localDir/sql4total.t
hive -f $localDir/sql4sex.t
hive -f $localDir/sql4device.t
hive -f $localDir/sql4mix.t > $localDir/data/$gday/result
echo "<<<Done"

scp /home/beitang.xz/appspy/data/$gday/result beitang.xz@$host:/home/beitang.xz/appspy/$gday.txt
scp /home/beitang.xz/appspy/data/$gday/result beitang.xz@login1.cm3.taobao.org:/home/beitang.xz/$gday.txt

echo ">>>Start importing"
curl -s "http://$host:7001/yuntiCallback?task=appspy&p=$gday"
echo "<<<Done"

echo ">>>Start running App Tuijian"
hive -f $localDir/sql4tuijian.t
hive -e 'select * from t_swapptj_app18_24_m' > $localDir/data_tj/18_24_m
hive -e 'select * from t_swapptj_app18_24_f' > $localDir/data_tj/18_24_f
hive -e 'select * from t_swapptj_app24_35_m' > $localDir/data_tj/24_35_m
hive -e 'select * from t_swapptj_app24_35_f' > $localDir/data_tj/24_35_f
hive -e 'select * from t_swapptj_app35_45_m' > $localDir/data_tj/35_45_m
hive -e 'select * from t_swapptj_app35_45_f' > $localDir/data_tj/35_45_f

scp /home/beitang.xz/appspy/data_tj/18_24_m beitang.xz@$host:/home/beitang.xz/apptj/18_24_m
scp /home/beitang.xz/appspy/data_tj/18_24_f beitang.xz@$host:/home/beitang.xz/apptj/18_24_f
scp /home/beitang.xz/appspy/data_tj/24_35_m beitang.xz@$host:/home/beitang.xz/apptj/24_35_m
scp /home/beitang.xz/appspy/data_tj/24_35_f beitang.xz@$host:/home/beitang.xz/apptj/24_35_f
scp /home/beitang.xz/appspy/data_tj/35_45_m beitang.xz@$host:/home/beitang.xz/apptj/35_45_m
scp /home/beitang.xz/appspy/data_tj/35_45_f beitang.xz@$host:/home/beitang.xz/apptj/35_45_f

echo "<<<Done"

echo ">>>Start importing AppTuijian"
curl -s "http://$host:7001/yuntiCallback?task=tuijian&p=$gday"

echo "<<<Done"
