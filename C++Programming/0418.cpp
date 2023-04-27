#include <iostream>
#include <string>

using namespace std;

class MyPos {
//private : Ŭ���� �ܺο��� ���� �Ұ�(��ӹ޾Ƶ� ���� �Ұ�)
//protected : Ŭ���� �ܺο��� ���� �Ұ�(��ӹ����� ����)
protected:
	float m_x, m_y;

public:
	MyPos(){
		m_x = 0;
		m_y = 0;
	}
	MyPos(float x, float y){
		m_x = x;
		m_y = y;
	}
	~MyPos() {
		cout<<"MyPos destructor called!"<<endl;
	}
	void print() {
		cout<<"("<<m_x<<", "<<m_y<<")"<<endl;
	}
};

//public�� ���� �ִ� �� �ƴϴ�. �׳� ������ �׷��ϴ�.
class MyColorPos : public MyPos{
private:
	string m_color;

public:
	MyColorPos()/*Ŭ������ ������ �ٸ� Ŭ������ �ִ� ���, �� �κп��� �� Ŭ������ �����ڰ� ȣ��ȴ�.
	�θ�Ŭ������ �⺻������ ���� ���⼭ �ҷ�����. �⺻ �����ڰ� ���� ��� ������ ����
	*/:MyPos(0,0), m_color("black") {
		//�θ𿡼� ���� ������ �θ𿡼� �����Ѵ�.
		//�츮 �ڽ� Ŭ���������� �ڽĿ��� ���� ������ ��������.
		m_color = "black";
	}	
	MyColorPos(float x, float y, string c) :MyPos(x, y), m_color(c) {
		
	}
	~MyColorPos() {
		//�߰��� �� �����ϰ�, �������� �����ϰ�,(����?)
		//�θ𲨴� �θ� �Ű澴��. �ڽĲ��� �ڽ��� �Ű澴��.
		cout<<"MyColorPos Destructor called!"<<endl;
	}
	void print() {		//�Լ� �������̵�(function overriding) : �ڽ� Ŭ�������� �θ� Ŭ������ ����� �ٲ۴�.
						//�������̵��� �Լ��� ��°�� �ٲ�ġ�Ⱑ �⺻ ���������, �θ� �Լ��� ��ɿ� ������ �� �߰��ϰ� �������� ����.
						
		MyPos::print();
		//m_x�� m_y�� private�̶� �ڽ� Ŭ���������� �������� ����.
		cout<<"color = "<<m_color<<endl;
	}
};

//"����� Ȯ���̴�." (�ڽ��� �θ𺸴� ũ��.)

int main() {
	
	//MyPos a(10,20);
	//a.print();

	////����Ʈ ������ ����� ������ ����
	//MyColorPos b;

	////�Ұ���
	////MyColorPos b(10,20);
	//b.print();


	MyColorPos b(30,40,"red");
	MyPos a;
	//b��ü�� a�� �ʿ��� ��� ��Ҹ� ������ �ִ�. b�� a�� ����� �� ����.
	//�ڽ�->�θ�, derived->base : "��ĳ����(���� ����ȯ)"
	//a = b;
	b.print();
	a.print();

	MyPos c(10,20);
	//�ݴ�� �ȵȴ�.
	//�θ�->�ڽ�, base->derived : "�ٿ�ĳ����(���� ����ȯ)"
	//MyColorPos d = c;

	MyPos *p1;
	p1 = &b;		//������ ��ĳ����(����)
	p1->print();	//�������� ������ Ÿ���� �켱�̴�. ��, �θ��� print() ȣ��

	MyColorPos *p2;
	//p2 = &a;		//������ �ٿ�ĳ����(�Ұ���)

	p2 = (MyColorPos*)p1;		//�̰� �ȴ�.(???)
	p2->print();	//�ڽ��� print()ȣ��

	return 0;
}