#!/usr/bin/env python
#coding=UTF-8

import os
import jumper-utils
        
if __name__=='__main__':
    jumpUtils = JumperUtils(
    'beitang.xz', 
    'taobao1234', 
    'login1.cm4.taobao.org'
    )
    
    jumpUtils.download('/home/beitang.xz/test','d:/tmp')
    
    jumpUtils.upload('/home/beitang.xz/test/a.pdf', 'd:/TDDownload/thinkcomplexity.pdf')
    
    os.system('pause')