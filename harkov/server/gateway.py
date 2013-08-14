#!/usr/bin/env python

#coding=UTF-8

import os
import web

urls = (
    '/upload', 'Upload',
    '/(.*)', 'Dispatcher'
)

app = web.application(urls, globals())

class Upload:
    def __init__(self):
        self._baseDir = 'D:/tmp'
    def GET(self):
        web.header('Content-Type', 'text/plain')
        return '{"success":"true", "data":""}'
    def POST(self):
        x = web.input(myfile={})
        web.debug(x['hostname'])
        web.debug(x['myfile'].filename)
        fname = x['myfile'].filename
        fout = open(self._baseDir +'/'+ x['hostname'] + '_' + fname, 'w')
        fout.write(x['myfile'].file.read())
        fout.close()
        raise web.seeother('/upload')
        
class Dispatcher:
    def __init__(self):
        self.core = Core()
  
    def GET(self, name):
        return self.REQ(name)

    def POST(self, name):
        return self.REQ(name, withForm = True)

    def REQ(self, name, withForm = False):
        params = web.input()
        
if __name__ == "__main__":
    app.run()