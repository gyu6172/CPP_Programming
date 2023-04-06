#pragma once
#ifndef __MY__STUDENT_H__
#define __MY__STUDENT_H__
#include <string>
#include <iostream>
using namespace std;
class Teacher;	//MyStudent와 친구기때문에 MyStudent의 멤버변수에 접근할 수 있음.
class MyStudent {
private:
	int m_id;
	string m_name;
	static int s_numStudent;
	static const int MAX_STUDENT;	//상수는 언제나 static이다.

public:
	MyStudent(string name);
	void print() {
		static int log=0;
		cout << log<<"[" << m_id << "]" << m_name << endl;
		log++;
	}
	static int getNumStudent();
	friend void recommendName(MyStudent &in);
	friend Teacher;
};
#endif