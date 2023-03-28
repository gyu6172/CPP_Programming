#include <iostream>		//�ý����� ���� �ִ� ǥ�� �������
using namespace std;

#include "MyLine0328.h"	//main.cpp�� ���� ��ġ�� �ִ� �������

void func(MyLine *in) {
	in->print();
	in->m_dim=3;
}

MyLine* func2() {
	MyLine out(0,0,0,0);
	return &out;
	//�Լ��� ������ �����. �� ����� �ȵȴ�.

	return new MyLine(0,0,0,0);	//�̰� �ȴ�.
}

int main() {
	
	MyLine a(10,20,30,40);
	MyLine b;

	func(&a);

	//������
	MyLine *p = nullptr;
	p = &a;

	p->print();

	a.print();
	b.print();

	//p = (MyLine*)malloc(sizeof(MyLine)); ����Ʈ ������ ����(�ٵ� ��)

	//new Ű����� �޸𸮸� ��(heap)���ٰ� ����
	p = new MyLine(4,5,6,7);

	delete(p);
	p=func2();

	p = new MyLine[10];
	p[0].print();
	delete []p;		//�迭 ������ ������ ��

	MyLine* p2[10];
	for (int i = 0; i < 10; i++) {
		p2[i] = new MyLine(i,0,i,0);
	}
	p2[0]->print();

	for (int i = 0; i < 10; i++) {
		delete p2[i];
	}

	return 0;
}