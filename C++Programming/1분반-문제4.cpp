#include <iostream>
using namespace std;

int getLength(const char* str) {
	int len=0;
	while (true) {
		if(str[len]==NULL)
			break;
		len++;
	}
	return len;
}

class MyString {
private:
	char* m_str;
	int m_length;

public:
	MyString(const char* str)
	{
		m_length = getLength(str);
		m_str = new char[m_length+1];
		for (int i = 0; i < m_length; i++) {
			m_str[i] = str[i];
		}
		m_str[m_length] = NULL;
	}

	MyString(const MyString& in) {
		m_length = in.m_length;
		m_str = new char[m_length+1];
		for (int i = 0; i < m_length; i++) {
			m_str[i] = in.m_str[i];
		}
		m_str[m_length] = NULL;
	}

	void Set(const char* in) {
		delete m_str;
		m_length = getLength(in);
		m_str = new char[m_length + 1];
		for (int i = 0; i < m_length; i++) {
			m_str[i] = in[i];
		}
		m_str[m_length] = NULL;
	}

	friend ostream& operator<<(ostream& o, MyString& in);
};

ostream& operator<<(ostream& o, MyString& in) {
	o<<in.m_str;
	return o;
}

int main() {
	MyString a("Sejong");
	MyString b = a;

	a.Set("University");

	cout<<a<<endl;
	cout<<b<<endl;
}