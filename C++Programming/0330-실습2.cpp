#include <iostream>
using namespace std;
void swap(int &c, int &d) {
	int tmp=c;
	c=d;
	d=tmp;
}

int g_a=30;
int &getGlobal() {
	//���� �� ��ü�� ����
	return g_a;
}
int main() {
	int a=10,b=20;
	int* p=&a;	//������(pointer) : ������ �ּ�
	int &r=a;	//������(reference) : ������ ����. ���� �� ���� �����.
	//r=b : a = b�ϴ� �Ͱ� ����.

	cout<<a<<", "<<b<<endl;
	swap(a, b);
	cout << a << ", " << b << endl;

	getGlobal() = 40;

	cout<<getGlobal()<<endl;

}