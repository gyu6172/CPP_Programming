#include <iostream>
#include <string>
#include "0323.h"
using namespace std;

int main() {						//���� ���� - stack�� ����
	
	MyCircle a;
	MyCircle b(10, "main-b");

	a.setRadius(20);

	a.print();
	b.print();
	
	cout<<"�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�"<<endl;

	return 0;	
}

MyCircle g_b(100, "global-b");

