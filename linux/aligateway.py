#!/usr/bin/env python
#coding=UTF-8

import os
import paramiko

class AliGw(object):
    currFile = None
    trans = None
    sftp = None
    
    @staticmethod
    def prgs4Cp(num, total):
        print '\rnow copying %s [%d / %d]'%(currFile, num, total),
    
    @staticmethod
    def prgs4Put(num, total):
        print '\rnow uploading [%d / %d]'%(num, total),

    def upload(self, remote, local):
        attr = self.sftp.put(local, remote, AliGw.prgs4Put)
        if attr is not None:
            print 'upload succeed.'
        else:
            print 'upload failed'
            
    def __init__(self, user, passwd, host):
        try:
            self.trans = paramiko.Transport((host, 22))
            self.trans.connect(username=user, password=passwd)
            self.sftp = paramiko.SFTPClient.from_transport(self.trans)
        finally:
            print 'failed to init'
            
    def __del__(self):
        if self.trans is not None: self.trans.close()
        if self.sftp is not None: self.sftp.close()    

    def download(self, dir, local):
        global currFile
        
        self.sftp.chdir(dir)
        dirs = self.sftp.listdir()
        print '%d files found to be transferred'%len(dirs)
        
        for s in dirs:
            currFile = s
            lf = '%s/%s'%(local, s)
            self.sftp.get(s, lf, AliGw.prgs4Cp)
            print '...ok'

