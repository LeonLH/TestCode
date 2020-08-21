#include <boost/regex.hpp>
#include <iostream>


using namespace std;

int main(){
	boost::regex regMac("hello");
	string Str = "hello";
	bool b = boost::regex_match(Str, regMac);
	cout << b << endl;
}
