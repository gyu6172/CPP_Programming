#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>
class MyString {
private:
	char *m_pStr;
	int m_length;

public:
	MyString();
	MyString(const char * in);
	MyString(const MyString& in);		//copy constructor
	~MyString();

	void assignMemory();
	void releaseMemory();

	int getLength() const {return m_length;}
	static int getLength(const char* in, int max_length=255);

	//cout<<MyString<<endl; 을 가능하게 하고 싶다
	friend std::ostream& operator<<(std::ostream& o, MyString& in);
	const MyString& operator=(const MyString& in);
	// c = a + b
	const MyString& operator+(const MyString& in);

	void append(const MyString& in);

};

#endif
