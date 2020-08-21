#encoding:utf-8
import time
import datetime

def test():
    stringLit = []
    strCredit = 'details____16842____'
    strNormal0 = 'details____12345____'
    strNormal1 = 'details____12346____'
    strNormal2 = 'details____12347____'
    strNormal3 = 'details____12348____'
    stringLit.append(strCredit)
    stringLit.append(strNormal0)
    stringLit.append(strNormal1)
    stringLit.append(strNormal2)
    stringLit.append(strNormal3)
    strSub = 'details____16'
    for strNode in stringLit:
        if strNode.find('details____16') != -1:
            print('找到了')
        else:
            print('没找到')

def test1():
    testInt = 20200712
    testStr2 = str(testInt)
    testStr1 = "hello"
    print testStr1 + testStr2

def test2():
    strDay = time.strftime("%Y%m%d", time.localtime())
    print strDay

def test3():
    testStr = u'\u672a\u627e\u5230\u5904\u7406\u51fd\u6570'
    testStr2 = u'\u627e\u4e0d\u5230\u6b63\u786e\u7684\u8c03\u7528\u63a5\u53e3'
    print testStr
    print testStr2

def test4():
    lit = []
    lit.append("hel")
    lit.append("hel")
    lit.append("hel")
    lit.append("hel")
    lit[0] = "zero"
    lit[1] = "one"
    print lit
if __name__ == "__main__":
    test4()
