#!/usr/bin/env python
#coding=UTF-8

import os
import jumper-utils
        
if __name__=='__main__':
    jumpUtils = JumperUtils(
    'abc', 
    '123', 
    'login1'
    )
    
    jumpUtils.download('/home/beitang.xz/test','d:/tmp')
    
    jumpUtils.upload('/home/beitang.xz/test/a.pdf', 'd:/TDDownload/thinkcomplexity.pdf')
    
    os.system('pause')
