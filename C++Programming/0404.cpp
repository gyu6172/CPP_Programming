#include <iostream>
using namespace std;
class MyString {
//모든 클래스는 생성자를 두개 호출
//1. 디폴트 생성자
//2. 복사 생성자
public:
	char *m_data;
	//MyString() {
	//	cout<<"default constructor!"<<endl;
	//	m_data = new char[100];
	//	m_data[0] = '\0';
	//}

	MyString(const MyString &in) {		//copy constructor
		cout << "copy constructor!" << endl;
		m_data = new char[100];
		for (int i = 0; i < 100; i++) {
			m_data[i] = in.m_data[i];
		}
	}

	const MyString& operator=(const MyString& in) {
		cout << "assignment operator!" << endl;
		for (int i = 0; i < 100; i++) {
			m_data[i] = in.m_data[i];
		}
		return in;
	}

	~MyString() {
		delete[] m_data;
	}

	MyString(const char* in) {
		cout<<"char pointer c: constructor"<<endl;
		m_data = new char[100];
		for (int i = 0; i < 100; i++) {
			m_data[i] = in[i];
			if (in[i] == '\0') {
				break;
			}
		}
		m_data[99] = '\0';
	}

	void print() {
		cout<<this<<endl;
		cout<<m_data<<endl;
	}

	void copyMineTo(MyString& in) {
		in = (*this);
	}
};

void func(MyString in) 
//여기서 메모리가 잡힌다. 즉, MyString in = a; <---카피 생성자 부른다.
{
	in.m_data[0] = 'X';
	cout<<"func!"<<endl;
	in.print();
}

void func2(int a=0) {
	cout<<a<<endl;
}

int func3(int a, int b=0) {
	int out=1;
	for (int i = 0; i < b; i++) {
		out *= a;
	}
	return out;
}


int main() {
	func2();
	func2(10);
	cout<<func3(2,4)<<endl;
	cout<<func3(4)<<endl;
	

	MyString d = "Sejong";
	d.print();



	MyString a;
	a.m_data[0] = 'a';
	a.m_data[1] = 'b';
	a.m_data[2] = 'c';
	a.m_data[3] = '\0';
	a.print();
	cout<< (&a) <<endl;

	//MyString b = a;	//디폴트 생성자를 부르지 않음

	//MyString b;
	//b=a;		//Assignment operator
	//a.m_data[0]='A';
	//b.print();

	MyString b;
	MyString c;
	c=b=a;
	b.print();
	c.print();


	//func(a);





	return 0;
}