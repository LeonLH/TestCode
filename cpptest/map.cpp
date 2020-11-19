#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, string> testFunc(bool isEmpty){
	if(isEmpty)
		return map<string, string>();
	else{
		map<string, string> tmp;
		string value = "world";
		tmp["hello"] = value;
		tmp["hello1"] = value;
		tmp["hello2"] = value;
		tmp["hello3"] = value;
		tmp["hello4"] = value;
		return tmp;
	}
}
int main(){
	map<string, string> resMap = testFunc(1);
	cout << resMap.size() << endl;
	return 0;
}


