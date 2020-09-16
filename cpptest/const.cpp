# include<list>
#include<iostream>

using namespace std;

int main(){
	list<int> l;
	l.push_back(123);
	l.push_back(124);
	l.push_back(125);

	for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
		cout << *it << endl;
		*it = 12;
	}
	return 0;
}
