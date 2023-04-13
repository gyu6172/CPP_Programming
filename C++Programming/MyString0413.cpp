#include "MyString0413.h"
MyString::MyString() {
	m_pStr = nullptr;
	m_length = 0;
}

MyString::MyString(const char* in) {
	m_pStr = nullptr;
	m_length = getLength(in);
	if(m_length == 0) return;

	assignMemory();
	
	for (int i = 0; i < m_length; i++) {
		m_pStr[i] = in[i];
	}
	m_pStr[m_length] = '\0';
}

MyString::MyString(const MyString& in) {
	/*
	* *this=in;
	* �� �� ���� �ִ�. �� �Ҵ� �����ڸ� ȣ���ϴ� ��.
	* ������ �̷��� �ϸ� ������. �Ҵ� �������� delete������ ���� �� ������� �ϴϱ� �׷���.
	* �׷��� ������ �����ʹ� Ư�� �ʱ�ȭ�� ������.
	*/
	m_pStr = nullptr;
	m_length = in.getLength();
	if(m_length == 0) return;

	assignMemory();
	
	for (int i = 0; i < m_length; i++) {
		m_pStr[i] = in.m_pStr[i];
	}
	m_pStr[m_length] = '\0';
}

MyString::~MyString() {
	releaseMemory();
}
void MyString::assignMemory()
{
	if(m_length==0)return;
	m_pStr = new char[m_length+1];
}
void MyString::releaseMemory()
{
	if(m_pStr != nullptr)
		delete[] m_pStr;
	m_pStr = nullptr;
	m_length = 0;
}
int MyString::getLength(const char* in, int max_length)
{
	if(nullptr){return 0;}


	int len=0;
	while (true) {
		if (in[len] == '\0') {return len;}
		if(len >= max_length){return len;}
		len++;
	}
}

std::ostream& operator<<(std::ostream& o, MyString& in)
{
	if(in.m_pStr == nullptr || in.getLength() == 0) return o;
	o << in.m_pStr;
	return o;
}

const MyString& MyString::operator=(const MyString& in) {
	//�Ҵ� �������� �ǹ� : in�� ���� ������?
	if (this == &in) {
		return *this;
	}

	releaseMemory();

	m_length = in.getLength();

	if (m_length == 0) return *this;
	m_pStr = new char[m_length + 1];
	for (int i = 0; i < m_length; i++) {
		m_pStr[i] = in.m_pStr[i];
	}
	m_pStr[m_length] = '\0';

	return *this;
}

void MyString::append(const MyString& in)
{
	if(in.getLength() == 0) return;

	MyString temp = *this;
	
	if(m_length>0) releaseMemory();
	m_length = temp.getLength() + in.getLength();

	assignMemory();

	for (int i = 0; i < temp.m_length; i++) {
		m_pStr[i] = temp.m_pStr[i];
	}
	for (int i = 0; i < in.m_length; i++) {
		m_pStr[i+temp.m_length] = in.m_pStr[i];
	}
	m_pStr[m_length] = '\0';
}

const MyString& MyString::operator+(const MyString& in)
{
	MyString out = *this;
	out.append(in);
	return out;

}
