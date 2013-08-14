#coding=UTF-8

def invoke(params):
    web = params['_web']
    session = params['_session']
    if session == None:
        raise web.seeother('/index')
        
    #read data from db and check
    session['authed'] = True
    from uuid import uuid4
    session['csrfToken'] = uuid4().hex
            
    if  params.has_key('redirect') == False:
        raise web.seeother('/' + params['_reqPage'])
    else:    
        raise web.seeother('/' + params['redirect'])