#coding=UTF-8

import os
import web
import configer
        
urls = (
    '/(.*)', 'Dispatcher'
)

action_path = 'action'
module_path = 'module'
screen_path = 'screen'
layout_path = 'layout'
widget_path = 'widget'

error_screen = '%s/error.py'%screen_path
default_layout = '%s/default.py'%layout_path
login_page = '/login'

class Core:
    def widget(self, name):
        try:
            wpath = '%s/%s.py'%(widget_path, name)
            w = web.template.frender(wpath)
            return w()
        except:
            return ''
    
    def session(self):
        return session

class Auth:
    def __init__(self, c):
        self.conf = c
    def checkLogin(self, name):
        allowList = self.conf['allowGuest']
        name = '/' + name
        for a in allowList:
            if a == name:
                return True
        if session.has_key('authed') and session['authed'] == True:
            return True
        return False
        
class Dispatcher:
    def __init__(self):
        self.core = Core()
    
    #++++++++    
    def GET(self, name):
        return self.DO(name)
    #--------
    
    #++++++++
    def POST(self, name):
        return self.DO(name, withForm = True)
    #--------
    
    #++++++++
    def DO(self, name, withForm = False):
        pageName = self.conv2IonName(name)
        #chk if access violation
        if pageName.startswith('shadow/'):
            pageName = 'error'

        params = web.input()
        params['_reqPage'] = name
        params['_session'] = session
        params['_web'] = web
        
        #check login
        if auth.checkLogin(name) == False: 
            raise web.seeother('%s?redirect=%s'%(login_page, name))
        
        #check if forward is set.
        if withForm and params.has_key('forwardTo'):
            pageName = params['forwardTo']

        #find module and process
        if withForm:
            ctx = self.actionProcess(params)
        else:
            ctx = self.moduleProcess(pageName, params)
        
        screen = self.loadScreen(pageName)
        layout = self.loadLayout(pageName)        
        content = screen(self.core, ctx)
        return layout(self.core, content)
    #--------
    
    def exists(self, path):
        return os.path.exists(path) and os.path.isfile(path)
    
    def conv2IonName(self, name):
        return name.replace('/', '_')
    
    def actionProcess(self, params):
        try:
            name = params['action']
            if name == None:
                return {}
            mod = self.loadAction(name)
        except Exception,e:
            return {}
        return mod.invoke(params)    
            
    def moduleProcess(self, name, params):
        try:
            mod = self.loadModule(name)
        except Exception,e:
            return {}
        return mod.invoke(params)
        
    def loadModule(self, name):
        mod = __import__(module_path + '.' + name)
        cls = getattr(mod, name)
        return cls
    
    def loadAction(self, name):
        mod = __import__(action_path + '.' + name)
        cls = getattr(mod, name)
        return cls
    
    def loadLayout(self, pageName):
        layoutPath = '%s/%s.py'%(layout_path, pageName)  
        if self.exists(layoutPath) == True:
            layout = web.template.frender(layoutPath)
        else:
            layout = web.template.frender(default_layout)
        return layout
        
    def loadScreen(self, pageName):
        screenPath = '%s/%s.py'%(screen_path, pageName)
        if self.exists(screenPath) == False:
            screen = web.template.frender(error_screen)
        else:
            screen = web.template.frender(screenPath)
        return screen
  
#####################################

app = web.application(urls, globals())
conf = configer.loadConf()
auth = Auth(conf)

if web.config.get('_session') is None:
    session = web.session.Session(app, web.session.DiskStore('sessions'), {'authed': False})
    web.config._session = session
else:
    session = web.config._session
    
if __name__ == "__main__":
    app.run()