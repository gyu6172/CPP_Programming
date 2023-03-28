#include "MyLine0328.h"
#include <iostream>
using namespace std;

MyLine::MyLine() : MyLine(0,0,0,0){
	
}

MyLine::MyLine(float x1, float y1, float x2, float y2): m_p1(x1,y1), 
														m_p2(x2,y2),
														m_dim(2)
{
	m_dim=2;
}

void MyLine::print() {
	cout<<"[Line] "<<m_p1.getString()<<"-"<<m_p2.getString()<<endl;
}