#include<iostream>

using namespace std;

int main(){
	string strDateToday;
	int idate = 20201118;
	char buffer[9] = {0};
	sprintf(buffer, "%d", idate);
	strDateToday = buffer;
	cout << strDateToday << endl;
	return 0;
}
