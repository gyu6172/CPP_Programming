#include "MyPlace.h"
#include<iostream>

MyPlace::MyPlace(string name, float distance)
{
	this->name = name;
	this->distance = distance;
}

void MyPlace::print()
{
	cout<<"�����"<<name<<"�Դϴ�."<<endl;
}
