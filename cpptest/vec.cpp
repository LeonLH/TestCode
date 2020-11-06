#include<iostream>

using namespace std;

class A{
	int i;
	public:
		void functionA();
	static void functionA();
};

void A::functionA(){
	cout << "non-static functionA" << endl;
};

int main(){
	A a;
	a.functionA();
	return 0;
}
