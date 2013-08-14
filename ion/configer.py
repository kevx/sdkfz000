#coding=UTF-8

import os
import json

conf_path = 'shadow'
main_conf = '%s/server.conf'%conf_path

def loadConf():
    f = open(main_conf, 'r')
    content = f.read()
    f.close()
    
    try:
        conf = json.loads(content)
        return conf
    except:
        print('!!!loads conf failed')
        return {}