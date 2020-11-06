#include <iostream>

using namespace std;
class A{
	double m_A;
	void m_funA();
};

void A::m_funA(){}

class B{
	double m_B;
	virtual void m_funB1();
	virtual void m_funB2();
};

void B::m_funB1(){}
void B::m_funB2(){}

class C : public B{
	virtual void m_funC1();
	virtual void m_funC2();
};

void C::m_funC1(){}
void C::m_funC2(){}

class D : public C{
	virtual void m_funD1();
	virtual void m_funD2();
};

void D::m_funD1(){}
void D::m_funD2(){}

int	 main(){

	A aaa;
	cout << "aaa: " << sizeof(aaa) << endl;

	B bbb;
	cout << "bbb: " << sizeof(bbb) << endl;

	C ccc;
	cout << "ccc: " << sizeof(ccc) << endl;

	D ddd;
	cout << "ddd: " << sizeof(ddd) << endl;
	return 0;
}
