#!/usr/bin/env python
#coding=utf8

import wb_login
import cookielib
import urllib2
import json
from pyquery import PyQuery as pq


def stripContent(s):
    p = s.find('//')
    if p < 0: return s.strip()
    else: return s[0:p].strip()
    
        
if __name__ == '__main__':
    username = 'v77@live.com'
    pwd = 's211ex'
    cookie_file = 'wb_login_cookies.dat'
    
    if wb_login.login(username, pwd, cookie_file):
        print 'Login WEIBO succeeded'
    else:
        print 'Login WEIBO failed'
        
    cookieJar = cookielib.LWPCookieJar()
    cookieJar.load(cookie_file)
    ##cookie_support = urllib2.HTTPCookieProcessor(cookieJar)
    ##opener = urllib2.build_opener(cookie_support)

    headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/28.0.1500.95 Safari/537.36', 
    'Host':'weibo.com'
    }
    
    cookieStr = ''
    for c in cookieJar:
        cookieStr = cookieStr + ' ' + c.name + '=' + c.value + '; '
    
    cookieStr = '''
    _s_tentry=-; Apache=8374358129221.946.1344066550639; lzstat_uv=3727219721092583063|2893156; v5reg=usrmdins1024; SINAGLOBAL=8374358129221.946.1344066550639; lzstat_ss=3173819639_0_1361957449_2893156; ssoln=v77%40live.com; sso_info=ln%3Dv77%2540live.com%26nick%3Dv77%26uid%3D1738094551; v=5; __utma=15428400.2075564415.1344227534.1362471781.1363250684.29; __utmc=15428400; __utmz=15428400.1363250684.29.27.utmcsr=blog.sina.com.cn|utmccn=(referral)|utmcmd=referral|utmcct=/s/blog_6befa6b401011nzu.html; appkey=3845272542; SSOLoginState=1372394026; WBStore=93a36335570f7c27|gn_logo; USRUG=usrmdins41459; USRHAWB=usrmdins312_189; ULV=1375177809318:1:1:1:8374358129221.946.1344066550639:; wvr=5; UOR=,weibo.com,blog.star7th.com; SinaRot_wb_r_topic=0; SUE=es%3D4749d286b246df3c4ceae614b993c5ae%26ev%3Dv1%26es2%3D65c6ea070112393710fc3f9fdf6da8f8%26rs0%3Dy28cZoBOhFRmjiBnhuzmNZxYTkL4AXlX1fkAtetM5L4Ik3fNgUbiEghtXVtXeacZcy%252BAvZpkxaHrLFo3ck%252F%252BP6fdhAVp0gA%252Bsi5m3z%252FzgnYF6Fbe8LMMxjepD8so4x4868fgEA9aoXRIsJSJY1F0hCGRfAs%252BaGNe%252FJCnetj26p8%253D%26rv%3D0; SUP=cv%3D1%26bt%3D1376455043%26et%3D1376541443%26d%3Dc909%26i%3Decae%26us%3D1%26vf%3D0%26vt%3D0%26ac%3D0%26st%3D0%26uid%3D1738094551%26name%3Dv77%2540live.com%26nick%3D%25E7%2594%25A8%25E6%2588%25B71738094551%26fmp%3D%26lcp%3D; SUS=SID-1738094551-1376455043-XD-g6kvb-218e368204d1c0105ef1d4c8ad8da05f; ALF=1379044299
    '''
    print(cookieStr)
    headers['Cookie'] = cookieStr
    
    req  = urllib2.Request(
        url = 'http://weibo.com/p/aj/mblog/mbloglist?pre_page=2&page=3&count=15&&id=1005051692760523&__rnd=232',
        data = None,
        headers = headers
    )
    result = urllib2.urlopen(req)
    txt = result.read()
    jsonobj = json.loads(txt)
    data = jsonobj['data']
    
    d = pq(data)
    nodes = d('.WB_text')
    for n in nodes:
        s = n.text.strip()
        s = s.replace('//', '')
        if len(s) == 0: continue
        print(s.encode('utf-8'))


    