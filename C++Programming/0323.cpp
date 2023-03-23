#include <iostream>
#include <string>
#include "0323.h"
using namespace std;

int main() {						//메인 변수 - stack에 저장
	
	MyCircle a;
	MyCircle b(10, "main-b");

	a.setRadius(20);

	a.print();
	b.print();
	
	cout<<"ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<<endl;

	return 0;	
}

MyCircle g_b(100, "global-b");

