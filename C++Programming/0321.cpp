#include <iostream>
using namespace std;

int g_numBox=0;		//Global Variable
					//��� : ���������� �տ� g_�� ���� ���̴�.

class MyBox {	//Class(���:�빮�ڷ� ����)
private:	//default : private
	int m_width;				//member variables(���:������� �տ��� m_�� ���� ���̴�.
	int m_height;	
	int m_area;
	void resetArea() {
		m_area = getArea();
	}

public:		//���� ������(visibility)

	MyBox() {		//constructor(������)
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
	

	void setHeight(int h) {			//member function(���:�ҹ��ڷ� ����)
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
	int a = m_width * m_height;		//local variable(���:���ú����� �տ� �ƹ��͵� �Ⱥ���)
	return m_width * m_height;
}
void MyBox::printBox() {
	cout << "[BOX] (" << m_width << ", " << m_height << ")";
	cout << " Area = " << getArea() << endl;
}
int main() {
	MyBox a;	//instance, Object, ��ü

	a.setWidth(20);
	a.setHeight(30);
	a.printBox();

	MyBox b(10,20);
	b.printBox();

	MyBox c(5);
	c.printBox();

	return 0;
}