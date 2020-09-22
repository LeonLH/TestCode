#include<assert.h>
#include<iostream>
#include<string>

using namespace std;
int main(){
	string sss = "测";
	// assert(sss == "\xe6\xb5\x8b");
	try
	{
		assert(0);
		cout << "hello world" << endl;
	}
	catch(...)
	{
		cout << "break!" << endl;
	}
	
	
	return 0;
}
