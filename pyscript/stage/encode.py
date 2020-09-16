# -*- coding: utf-8 -*-
import chardet
import MySQLdb
import json
import os
import sys

# lit = []
# lit.append("hello")
# lit.append("world")
# lit.append("interest")
# 
# for i in range(len(lit)):
#     print i, lit[i]

def test():
    str = 'test_\u93b6\u66e1\u796b\u7f01\u5fd5\u608a'

    print chardet.detect(str)
    if isinstance(str, unicode):
        print "is unicode"
    else:
        print "isn't unicode"

    str = str.decode('utf-8')
    if isinstance(str, unicode):
        print "is unicode"
    else:
        print "isn't unicode"

    str = str.encode("GBK")
    print str

def test2():
    mysqlConn = MySQLdb.connect(host = "127.0.0.1",
            user = "root",
            passwd = "c2yisno1",
            port = 3306,
            db = "test",
            charset = 'utf8mb4',
            )

    strG = u'12\u5e73\u56fd\u8d44'
    strG1 = u'11\U0002ef7b\u0376'
    strG3 = u'\u0376'
    strInsert = u"insert into account (id, name) values(1010, 'REPLACE');"
    cursor = mysqlConn.cursor()
    # strInsert = strInsert.replace("REPLACE", strG)
    strInsert = strInsert.replace("REPLACE", strG1)
    print strInsert
    cursor.execute(strInsert)
    cursor.execute('commit')

def test1():
    str1 = '\xF0\xAE\xBD\xBB\xCD\xB6'
    strG1 = u'11\U0002ef7b\u0376'
    try:
        str2 = str1.decode('utf-8')
    except:
        print('run into except')
        str2 = str1.decode('gbk')
    print(type(str2))
    print chardet.detect(str1)

def test2():
    str1 = '\xF0\xAE\xBD\xBB\xCD\xB6'
    strG1 = u'11\U0002ef7b\u0376'
    try:
        str2 = str1.decode('gbk')
    except:
        print('run into except')
        str2 = str1.decode('utf-8')
    print(type(str2))
    print chardet.detect(str1)

def test3():
    str1 = '你好，明天'
    try:
        str2 = str1.decode('utf-8')
    except UnicodeDecodeError:
        print('run into except: UnicodeDecodeError')
    except Exception, arg:
        print 'other exception\n', arg

    print str2

def test4():
    str1 = "{u'ErrorMsg': u'\u672a\u627e\u5230\u5904\u7406\u51fd\u6570', u'ErrorID': 200005}"
    strU    = u'\u672a\u627e\u5230\u5904\u7406\u51fd\u6570'
    strStrU =  '\u672a\u627e\u5230\u5904\u7406\u51fd\u6570'
    strStrC = u'\u65ad\u5f00'
    print strU
    print strStrU

    print strStrC
    # print repr(str2)

def test5():
    A = {}
    A["one"] = 111
    A["two"] = 222
    A["three"] = "三"
    # AJson = json.dumps(A, ensure_ascii=False)
    AJson = json.dumps(A, ensure_ascii=True)
    print AJson

def test6():
    aaa = "\xe6\xb5\x8b"
    print chardet.detect(aaa)
    print aaa

def test7():
    DIR = "/home/leon/workspace"
    for root, dirs, files in os.walk(DIR):
        print root, dirs
        break

def test8():
    for aaa in range(1):
        print aaa

if __name__=="__main__":
    test8()
