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


if __name__=="__main__":
    testRangeOfString()
    

