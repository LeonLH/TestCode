#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <boost/assign.hpp>
#include <boost/lexical_cast.hpp>


using namespace std;
int main(){
	list<int> l = boost::assign::list_of(23)(1234)(34);
	vector<int> v = boost::assign::list_of(23)(1234)(34); 
	vector<string> vStr = boost::assign::list_of("asdf")("asdf")("889");
// 	for(auto a:l)
// 		cout << a << endl;
// 	cout << "v:" << endl;
// 	for(auto a:v)
// 		cout << a << endl;
// 	cout << "vStr" << endl;
// 	for(auto a:vStr)
// 		cout << a << endl;
	int i = boost::lexical_cast<int>("8908");
	string a = boost::lexical_cast<string>(98);
	cout << i << endl;
	cout << a << endl;

    return 0;
}
