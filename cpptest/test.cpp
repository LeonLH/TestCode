#include<iostream>
using namespace std;

int main(){
	int a = 1;
	//int *pnLeft = &a;
	int *pnLeft = new int(1);
	cout << *pnLeft << endl;
	
	--(*pnLeft);

	cout << *pnLeft << endl;
	return 0;
}
