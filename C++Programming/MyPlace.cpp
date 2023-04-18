#include "MyPlace.h"
#include<iostream>

MyPlace::MyPlace(string name, float distance)
{
	this->name = name;
	this->distance = distance;
}

void MyPlace::print()
{
	cout<<"여기는"<<name<<"입니다."<<endl;
}
