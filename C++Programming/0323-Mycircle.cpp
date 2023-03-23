#include "0323.h"
#include <iostream>
#include <string>
using namespace std;
MyCircle::MyCircle(float r, string name) {
	m_idx = g_numCircle;
	m_name = name;
	setRadius(r);
	cout << "[Circle:" << m_name << "] constructed" << endl;
	g_numCircle++;
}
MyCircle::~MyCircle() {
	cout << "[Circle:" << m_name << "] destructed" << endl;
}
void MyCircle::print()
{
	cout << "[Circle:" << m_name << "] r=" << getRadius() << endl;
}

MyCircle g_a(100, "global-a");		//global - heap에 저장

void func() {						//함수 - stack에 저장
	MyCircle a(1, "func-a");
	MyCircle b(1, "func-b");
}