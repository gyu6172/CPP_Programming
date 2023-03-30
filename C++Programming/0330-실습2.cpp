#include <iostream>
using namespace std;
void swap(int &c, int &d) {
	int tmp=c;
	c=d;
	d=tmp;
}

int g_a=30;
int &getGlobal() {
	//변수 그 자체를 리턴
	return g_a;
}
int main() {
	int a=10,b=20;
	int* p=&a;	//포인터(pointer) : 변수의 주소
	int &r=a;	//참조자(reference) : 변수의 별명. 만들 때 값을 줘야함.
	//r=b : a = b하는 것과 같다.

	cout<<a<<", "<<b<<endl;
	swap(a, b);
	cout << a << ", " << b << endl;

	getGlobal() = 40;

	cout<<getGlobal()<<endl;

}