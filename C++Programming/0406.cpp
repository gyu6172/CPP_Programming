#include <iostream>
#include <string>
#include "MyStudent0406.h"
using namespace std;


class MyMath {		//wrapper class
public:
	static const double PI;
	static int add(int a, int b);
	static int multiply(int a, int b);
};
const double MyMath::PI=3.14;
int MyMath::add(int a, int b)
{
	return a+b;
}

int MyMath::multiply(int a, int b)
{
	return a*b;
}

void func() {
	static int fcount=0;	//�Լ� �ӿ��� �����ϴ� ��������(???)
	if (fcount == 0) {
		cout<<"your first call! : "<<fcount<<endl;
	}
	else {
		cout<<"you already call me! : "<<fcount<<endl;

	}
	fcount++;
}

class MyKey{
private:
	int m_data;
	MyKey() {
		m_data=10;
	}
public:
	
	static MyKey *KEY();

};

MyKey* MyKey::KEY() {
	static MyKey* m_pKey=nullptr;
	if (m_pKey == nullptr) {
		m_pKey = new MyKey();
	}
	return m_pKey;
}
int main() {
	MyKey::KEY();

	func();
	func();

	//single ton

	MyStudent a("Kim");

	MyStudent b("Lee");

	a.print();
	b.print();
	b.print();
	b.print();
	b.print();
	b.print();

	cout<<MyStudent::getNumStudent()<<"���� �л��� �ִ�."<<endl;

	return 0;
}


