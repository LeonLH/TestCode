#encoding:utf-8



str1 = u'盛信8期A'
print type(str1)
str2 = str1.encode('GBK')
print type(str2)

# str3 = str2.decode('utf-8')
# print type(str3)


str4 = u'\u4e0a\u6d77\u65b0\u4e09\u677f\u6a21\u62df'
print str4

str5 = u"\u614e\u77e5\u8d44\u4ea7\u5df1\u77e5\u79c1\u52df\u8bc1\u5238\u6295\u8d44\u57fa\u91d1"
print str5
