# coding: utf-8

import os
import time

def test():
    allFileName = "D:\\Workspace\\需求\\财信对接资讯\\20200916"
    maxDate = "20200916"
    GBXX_PATH = os.path.join(allFileName, "GBXX_"+maxDate+".xls")
    print GBXX_PATH
    if os.path.exists(GBXX_PATH):
        print "exists"
    else:
        print "no exists"

def testExcept():
    try:
        startTime = time.time()
        os.path.exist(GBXX_PATH)
    except NameError, ex:
        print "hello world"
        print type(ex.message)
    except Exception, e:
        print e.message

def testRangeOfString():
    print "len of dealRepurchase is: ", len("dealRepurchase")
    Len = len("dealRepurchase") + 4
    # testStr = "ItsmOpSeq____20201011"
    testStr = "dealRepurchase____20200731____2____11172____11172____49____1000000212____________flag"
    afterStr = testStr[Len:Len+8]
    print afterStr



def testTime():
    Timedate = time.mktime(time.strptime("20201010", "%Y%m%d"))
    print type(Timedate)
    print Timedate
    Timedate = int(Timedate)
    print Timedate


def isSFFtOption(m_strInstrumentID, m_strExchangeID):
    falg = False
    strInstr = "au*****?|cu*****?|al*****?|ru*****?"
    list = strInstr.split("|")
    for tmp in list:
        for c, b in zip(tmp, m_strInstrumentID):
            falg = True
            if c == '*':
                continue
            if c == '?':
                break
            if c != b:
                falg = False
                break
        if falg == True:
            return falg
    return falg

def isZFFtOption(m_strInstrumentID, m_strExchangeID):
    # if m_strInstrumentID == "CFFEX":
    #    return False
    falg = False
    strInstr = "SR****?|CF****?|TA****?|MA****?|RM****?"
    list = strInstr.split("|")
    for tmp in list:
        print "==="
        for c, b in zip(tmp, m_strInstrumentID):
            print c, b
            falg = True
            if c == '*':
                continue
            if c == '?':
                break
            if c != b:
                falg = False
                break
        if falg == True:
            return falg
    return falg

def isDFFtOPtion(m_strInstrumentID, m_strExchangeID):
    falg = False
    strInstr = "m****-*-?|c****-*-?|i****-*-?|y****-*-?|p****-*-?|j****-*-?|jm****-*-?"
    list = strInstr.split("|")
    for tmp in list:
        for c, b in zip(tmp, m_strInstrumentID):
            falg = True
            if c == '*':
                continue
            if c == '?':
                break
            if c != b:
                falg = False
                break
        if falg == True:
            return falg
    return falg
    
def isIfOption(m_strInstrumentID, m_strExchangeID):
    falg = True
    strInstr = "HO?|IO?|IF?^&&IO?"
    list = strInstr.split("|")
    for tmp in list:
        for c, b in zip(tmp, m_strInstrumentID):
            falg = True
            if c == '*':
                continue
            if c == '?':
                break
            if c != b:
                falg = False
                break
        if falg == True:
            return falg
    return falg
            
#def isIntlOption(m_strInstrumentID, m_strExchangeID):

def isFutureOptionInstrument(m_strExchangeID, m_strInstrumentID):
    falg = isZFFtOption(m_strInstrumentID, m_strExchangeID) or isDFFtOPtion(m_strInstrumentID, m_strExchangeID) or isSFFtOption(m_strInstrumentID, m_strExchangeID) or isIfOption(m_strInstrumentID, m_strExchangeID)
    return falg
if __name__=="__main__":
    print isFutureOptionInstrument("", "IC2101")
    





















