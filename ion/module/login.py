#coding=UTF-8

def invoke(params):
    redirectUrl = params['redirect']
    print '###redirectUrl=' + redirectUrl
    return {'redirectTo': redirectUrl}
