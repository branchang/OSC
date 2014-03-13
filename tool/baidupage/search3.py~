#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
百度关键词排名
By Jibo He @ ueseo.org
hej...@ueseo.org
26 Oct, 2011
http://www.ueseo.org/download/python/BaiduResult.py
'''
import sys
import urllib ,urllib2
import re

def getNakedDomain(url):
    '''
    return the naked domain based on url
    '''
    if url.startswith('http://'):
        url=url[7:]
    if url.startswith('www.'):
        url=url[4:]
    if "/" in url:
        url =url[0:url.find('/')]

    return url

def baidu100(w):
    url= "http://www.baidu.com/s?"
    values = {
    "w":w.encode('gbk','ignore')
    }
    data = urllib.urlencode(values)
    newurl = url + data+"&rn=100"
    response = urllib2.urlopen(newurl)
    the_page = response.read().decode('gbk','ignore')
    return the_page

def baidu10(w):
    url= "http://www.baidu.com/s?"
    values = {
    "w":w.encode('gbk','ignore')
    }
    data = urllib.urlencode(values)
    newurl = url + data
    response = urllib2.urlopen(newurl)
    the_page = response.read().decode('gbk','ignore')
    return the_page

def ResultLinksFilter(data,mysite):
    o = re.compile('''href="(.+?)"''')
    f = o.findall(data)
    line = 1
    isInFirst100 = False
    for ff in f:
        if not re.search("baidu",ff) and not re.search("bing",ff) and
ff.startswith('http://'):

            if getNakedDomain(mysite) in ff:
                isInFirst100 = True
                break

                #print "******* " ,line ,ff
            #print line ,ff
            line += 1
    if isInFirst100:
        return isInFirst100,line,ff
    else:
        return isInFirst100,-1,'-1'

if __name__ == "__main__":
    mysite = 'pconline.com.cn'
    keyword='手机'

    mysite = 'http://www.ueseo.org'
    mysite = 'http://ueseo.org'
    mysite = 'http://blog.ueseo.org'
    #mysite = 'http://bbs.ueseo.org'
    keyword='ueseo'
    keyword='优异搜索'

    data = baidu100(keyword.decode('utf-8'))
    isInFirst100,line,link =ResultLinksFilter(data,mysite)
    print line,link 
