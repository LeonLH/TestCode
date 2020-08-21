#include<iostream>
#include<string>
#include<vector>
#include<boost/lexical_cast.hpp>
#include<boost/algorithm/algorithm.hpp>
#include<boost/algorithm/string/join.hpp>
#include<set>

using namespace std;
int test(){
	string num = "234";
	int inum = boost::lexical_cast<int>(num);
	// cout << inum << endl;
	vector<int> vec{2134,4546,767,87};
	vec.push_back(898);
	vec.push_back(898);
	vec.push_back(980);
	cout << vec.front() << endl;
	for(auto i: vec)
		cout << i << endl;
	return 0;
}

int main(){
	set<string> cmdIds;
	cmdIds.insert("1234");
	cmdIds.insert("1236");
	cmdIds.insert("1238");
	// for(auto i : cmdIds)
		// cout << i << endl;
 	string str = boost::algorithm::join(cmdIds, ",");
 	cout << str << endl;
	return 0;
}
