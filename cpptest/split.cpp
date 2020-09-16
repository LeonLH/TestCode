#include <boost/algorithm/string.hpp>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int test(){
	string testStr = "132::1234:1234:1234:12";
	cout << testStr << endl;
	vector<string> vec;
	boost::split(vec, testStr, boost::is_any_of(":"));

	for(auto tmp : vec)
		cout << tmp << endl;

	int h;
	cout << "please input a hex number:" << endl;
	cin >> std::hex >> h;
	cout << h << endl;
	return 0;
}

int main(){
	string strPriKeytag1 = "";
	string strPriKeytag2 = "";
	boost::regex reg(KEY_SPLITTER);
    boost::sregex_token_iterator it(strPriKeytag.begin(), strPriKeytag.end(), reg, -1);
    boost::sregex_token_iterator end;
	return 0;
}
