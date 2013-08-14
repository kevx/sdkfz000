#应用发现v1版
#beitang.xz@08/23/2012

#相关表，以t_开头的表均为临时表（每次跑数据之前会drop然后新建）

t_swappspy_sampling     采样表，随机抽取5000条数据之后的记录
t_swappspy_total        总量表
t_swappspy_sex_male     男性装机量表
t_swappspy_sex_female   女性装机量表
t_swappspy_device       设备临时装机量表
t_swappspy_device1      低端设备装机量表
t_swappspy_device2      中端设备装机量表
t_swappspy_device2      高端设备装机量表

#以上表数据跑完后，将由sql4mix进行全部合成
sql4mix里面含有一个总控阀值，控制入库的应用数
即总装机量低于多少的应用不会入库，之所以这样是为了避免无效的数据过多，
因为有85%的应用总装机量低于10（用户样本为5000），

