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
	MyString(){m_length = 0;m_str=nullptr;}
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

	~MyString() {
		if (m_str != NULL) {
			delete[] m_str;
		}
	}

	void Set(const char* in) {
		delete[] m_str;
		m_length = getLength(in);
		m_str = new char[m_length + 1];
		for (int i = 0; i < m_length; i++) {
			m_str[i] = in[i];
		}
		m_str[m_length] = NULL;
	}


	friend ostream& operator<<(ostream& o, MyString& in);
	friend MyString& operator+(const char* str, const MyString& in);
	MyString& operator+=(const MyString& in);
};

MyString& MyString::operator+=(const MyString& in) {
	char* tmp_str = new char[m_length+1];
	for (int i = 0; i < m_length; i++) {
		tmp_str[i] = m_str[i];
	}
	tmp_str[m_length] = NULL;

	m_length += in.m_length;

	delete[] m_str;
	m_str = new char[m_length+1];

	for (int i = 0; i < m_length; i++) {
		if (i < getLength(tmp_str)) {
			m_str[i] = tmp_str[i];
		}
		else {
			m_str[i] = in.m_str[i - getLength(tmp_str)];
		}
	}
	m_str[m_length] = NULL;

	delete[] tmp_str;

	return *this;
}

MyString& operator+(const char* str, const MyString& in) {
	MyString* tmp = new MyString;
	tmp->m_length = getLength(str) + in.m_length;
	tmp->m_str = new char[tmp->m_length + 1];
	for (int i = 0; i < tmp->m_length; i++) {
		if (i < getLength(str)) {
			tmp->m_str[i] = str[i];
		}
		else {
			tmp->m_str[i] = in.m_str[i-getLength(str)];
		}
	}
	tmp->m_str[tmp->m_length] = NULL;
	return *tmp;
}

ostream& operator<<(ostream& o, MyString& in) {
	o<<in.m_str;
	return o;
}

int main() {
	MyString a("Sejong");
	MyString b = a;

	a.Set("University");

	b += " "+a;

	cout<<a<<endl;
	cout<<b<<endl;
	
	
}