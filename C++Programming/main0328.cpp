#include <iostream>		//시스템이 갖고 있는 표준 헤더파일
using namespace std;

#include "MyLine0328.h"	//main.cpp와 같은 위치에 있는 헤더파일

void func(MyLine *in) {
	in->print();
	in->m_dim=3;
}

MyLine* func2() {
	MyLine out(0,0,0,0);
	return &out;
	//함수가 끝나면 사라짐. 이 방법은 안된다.

	return new MyLine(0,0,0,0);	//이건 된다.
}

int main() {
	
	MyLine a(10,20,30,40);
	MyLine b;

	func(&a);

	//포인터
	MyLine *p = nullptr;
	p = &a;

	p->print();

	a.print();
	b.print();

	//p = (MyLine*)malloc(sizeof(MyLine)); 디폴트 생성자 생성(근데 모름)

	//new 키워드는 메모리를 힙(heap)에다가 생성
	p = new MyLine(4,5,6,7);

	delete(p);
	p=func2();

	p = new MyLine[10];
	p[0].print();
	delete []p;		//배열 포인터 삭제할 때

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