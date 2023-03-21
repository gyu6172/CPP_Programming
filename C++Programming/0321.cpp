#include <iostream>
using namespace std;

int g_numBox=0;		//Global Variable
					//약속 : 전역변수는 앞에 g_를 붙일 것이다.

class MyBox {	//Class(약속:대문자로 시작)
private:	//default : private
	int m_width;				//member variables(약속:멤버변수 앞에는 m_을 붙일 것이다.
	int m_height;	
	int m_area;
	void resetArea() {
		m_area = getArea();
	}

public:		//접근 지정자(visibility)

	MyBox() {		//constructor(생성자)
		m_width=1;
		m_height=1;
		resetArea();
		cout<<"calling constructor!"<<endl;
	}

	MyBox(int w){
		m_width = w;
		m_height = w;
		resetArea();
		cout << "calling constructor" << endl;
	}
	MyBox(int w, int h){
		m_width = w;
		m_height = h;
		resetArea();
		cout<<"calling constructor"<<endl;
	}
	

	void setHeight(int h) {			//member function(약속:소문자로 시작)
		m_height = h;
		resetArea();
	}
	void setWidth(int w) {
		m_width = w;
		resetArea();
	}
	int getArea();
	void printBox();
};
int MyBox::getArea() {
	int a = m_width * m_height;		//local variable(약속:로컬변수는 앞에 아무것도 안붙임)
	return m_width * m_height;
}
void MyBox::printBox() {
	cout << "[BOX] (" << m_width << ", " << m_height << ")";
	cout << " Area = " << getArea() << endl;
}
int main() {
	MyBox a;	//instance, Object, 객체

	a.setWidth(20);
	a.setHeight(30);
	a.printBox();

	MyBox b(10,20);
	b.printBox();

	MyBox c(5);
	c.printBox();

	return 0;
}