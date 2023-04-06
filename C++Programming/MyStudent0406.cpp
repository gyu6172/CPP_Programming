#include "MyStudent0406.h"
int MyStudent::s_numStudent = 0;
const int MyStudent::MAX_STUDENT=100;
int MyStudent::getNumStudent() {
	return MyStudent::s_numStudent;
}
MyStudent::MyStudent(string name)
{
	m_name = name;
	m_id = s_numStudent++;
}


void recommendName(MyStudent &in) {
	in.m_name = "NoName";
}
