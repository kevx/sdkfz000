--Final step

select tt.pkg, tt.cnt, 
    if(tm.cnt is null, 0, tm.cnt), 
    if(tf.cnt is null, 0, tf.cnt), 
    if(td1.cnt is null, 0, td1.cnt), 
    if(td2.cnt is null, 0, td2.cnt), 
    if(td3.cnt is null, 0, td3.cnt) 
from t_swappspy_total tt 
left outer join t_swappspy_sex_male tm on (tt.pkg = tm.pkg) 
left outer join t_swappspy_sex_female tf on (tt.pkg = tf.pkg) 
left outer join t_swappspy_device1 td1 on (tt.pkg = td1.pkg) 
left outer join t_swappspy_device2 td2 on (tt.pkg = td2.pkg) 
left outer join t_swappspy_device3 td3 on (tt.pkg = td3.pkg)
where tt.cnt >= 10
