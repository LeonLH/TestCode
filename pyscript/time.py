#encoding:utf-8

import time
import datetime

def testTime():
    startTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    print(startTime)

def testx():
    for i in xrange(5):
        print i

def testQueryDataFromTT():
    dict = {u'resp': {u'SZ': [1591286400000L, 1591200000000L, 1591113600000L, 1591027200000L, 1590940800000L], u'SH': [1591286400000L, 1591200000000L, 1591113600000L, 1591027200000L, 1590940800000L]}, u'success': True}
    for item in dict["resp"]:
        for index in xrange(len(dict["resp"][item])):
            dict["resp"][item][index] = time.strftime('%Y%m%d',time.localtime(dict["resp"][item][index]/1000)) 
    print dict
    return dict

def test():
    dict = testQueryDataFromTT()

    print dict

    dictTmp = {}
    for item in dict["resp"]:
        print dict["resp"][item]
        dict["resp"][item].sort(reverse = True)
        if(len(dict["resp"][item])>=2):
            # 修改列表的下标以改变保留的天数，例如，保留2天，则改成1；保留5天，则改成4；最多可以保留5天。
            dictTmp[item] = dict["resp"][item][2]
        else:
            dictTmp[item] = minCacheTime
    print dictTmp
    return dictTmp

def testM():
    dictTmp = {u'SZ': '20200602', u'SH': '20200603', u'SO': '20200601'}
    min_value = min(dictTmp.values())
    print min_value

    min_keys = [k for k, v in dictTmp.items() if v == min_value]
    print min_keys
    print min_value
    minTime[min_keys[0]] = min_value
    return minTime

minTime = {}
# minTime = testM()

if __name__ == "__main__":
    curTime = time.strftime('%Y%m%d',time.localtime(time.time()))
    print curTime

