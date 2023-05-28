#include <iostream>
#include <string>
int getLength(const char* str) {
	int len=0;
	for (int i = 0; str[i] != NULL; i++) {
		len++;
	}
	return len;
}
using namespace std;
class MyString {
private:
	char* m_str;

public:
	MyString(){
		
	}
	MyString(const char* str){
		m_str = new char[getLength(str)+1];
		for (int i = 0; str[i] != NULL; i++) {
			m_str[i] = str[i];
		}
		m_str[getLength(str)] = NULL;
	}
	MyString(MyString& in) {
		m_str = new char[getLength(in.m_str)+1];
		for (int i = 0; i < getLength(in.m_str); i++) {
			m_str[i] = (in.m_str)[i];
		}
		m_str[getLength(in.m_str)] = NULL;

	}
	void Set(const char* str);
	void print();

	MyString& operator+(const char* str);
	friend MyString& operator+(const char* str, MyString& in);
	MyString& operator+=(const char* str);
};
int main() {
	MyString a("Sejong");
	MyString b = a;

	a.Set("University");

	a.print();
	b.print();

	return 0;
}

void MyString::Set(const char* str)
{
	delete m_str;
	m_str = new char[getLength(str)+1];
	for (int i = 0; str[i] != NULL; i++) {
		m_str[i] = str[i];
	}
	m_str[getLength(str)] = NULL;
}

void MyString::print() {
	cout<<m_str<<endl;
}

MyString& MyString::operator+(const char* str) {
	int len = getLength(str) + getLength(m_str) + 1;
	char* out = new char[len];
	int i=0;
	for (; i < len-1; i++) {
		if (i < getLength(m_str)) {
			out[i] = m_str[i];
		}
		else {
			out[i] = str[i-getLength(m_str)];
		}
	}
	out[i] = NULL;
}

MyString& operator+(const char* str, MyString& in) {
	int len = getLength(str) + getLength(in.m_str) + 1;
	char* out = new char[len];
	int i = 0;
	for (; i < len - 1; i++) {
		if (i < getLength(str)) {
			out[i] = str[i];
		}
		else {
			out[i] = in.m_str[i-getLength(str)];
		}
	}
	out[i] = NULL;
}

MyString& MyString::operator+=(const char* str) {
	
}