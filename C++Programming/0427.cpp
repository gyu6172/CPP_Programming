#include <iostream>
#include <string>
using namespace std;

class MyShape {
protected:
	float m_x, m_y;

public:
	MyShape() {
		m_x = 0;
		m_y = 0;
	}
	MyShape(float x, float y) {
		m_x = x;
		m_y = y;
	}
	//�Լ� ������ �̷� �� �ִ�.
	//�̷� �Լ��� ���� �����Լ�, �Ǵ� �߻��Լ� ��� �Ѵ�.
	//�Լ��� ������ ������ �̷�ٴ� ���̴�.
	//virtual void firstClick(float x, float y) = 0;	<--���� ������ �ؾ���
	//virtual void dragging(float x, float y){};		<--���� �ص� �ǰ� ���ص� ��
	//virtual void endClick(float x, float y){};

	//�߻� �Լ��� ���� Ŭ������ �߻� Ŭ����(abstract class)��� �Ѵ�.
	//�߻� Ŭ������ ��ü�� �� ����. �� �θ�θ� Ȱ���ϰڴ�.
	//�߻� Ŭ������ ��ӹ޴� Ŭ�������� �Լ� �������̵��� �����Ѵ�.
	virtual void draw() = 0;
	/*{
		cout<<"[SHAP] ("<<m_x<<", "<<m_y<<")"<<endl;
	}*/
};

class MyRect : public MyShape{
//���� ���� �ִ� ��������� �Ű澲��.
private:
	float m_width,m_height;

public:
	MyRect(){
		m_width = 1;
		m_height = 1;
	}
	MyRect(float x, float y) : MyShape(x, y) {
		m_width = 1;
		m_height = 1;
	}
	MyRect(float x, float y, float w, float h) : MyShape(x,y){
		m_width = w;
		m_height = h;
	}
	void draw() {		//overriding
		//���� �������̵��� �θ� �����ִ°� ���� �ϰ� �ڽĲ��� ���� �Ѵ�. �̰� ����
		//MyShape::draw();
		//�׷��� �� ���� ��µǸ� ���̻ڴϱ� �̹����� �θ� Ŭ������ ��������� protected�� ����.
		cout<<"[RECT] ("<<m_x<<", "<<m_y<<"), width="<<m_width<<", height="<<m_height<< endl;
	}

};

class MyCircle : public MyShape{
private:
	float m_radius;

public:
	MyCircle() {
		m_radius = 1;
	}
	MyCircle(float x, float y) : MyShape(x, y) {
		m_radius = 1;
	}
	MyCircle(float x, float y, float r) : MyShape(x, y) {
		m_radius = r;
	}
	void draw() {
		cout << "[CRCL] (" << m_x << ", " << m_y << "), r="<<m_radius << endl;
	}
};

class MyLine :public MyShape {
private:
	float m_x2, m_y2;
public:
	MyLine() {
		m_x2 = 0;
		m_y2 = 0;
	}
	MyLine(float x1, float y1, float x2, float y2) :MyShape(x1, y1) {
		m_x2 = x2;
		m_y2 = y2;
	}
	void draw() {
		cout<<"[Line] ("<<m_x<<", "<<m_y<<") ~ ("<<m_x2<<", "<<m_y2<<")"<<endl;
	}
};

int main() {
	//������ �ٸ� Ŭ������ ���� �迭�� ���� �� ������?
	//MyShape a(20,30);
	MyRect b(10,20,3,3);
	MyCircle c(0,0,10);

	//����Լ��� �⺻������ ������Ÿ���� ���󰣴�.
	//��, �θ��� draw() ȣ���Ѵ�.

	//�Լ��� ���� �޸�(�ּҰ�)�� �ִ�.
	//MyShape* p = &a;
	//�����Ϸ� : �� p�� MyShape����. draw()�� ���⿡ ��������.
	//�����Ϸ��� ������Ÿ�ӿ� �Լ��� �ּҸ� ������.
	//�׷��� �ּҸ� �̸� �������� ���ڰ� �ϴ� ������ �ִ�.(���߿� ã��) : virtual Ű����
	//virtual �Լ��� ���߿� �������̵� �� ���ɼ��� �ִٴ� ��.
	//binding : �Լ� �̸��� �ּҸ� ��Ī�ϴ� ��.
	//virtual�Լ��� �����ϴܰ迡�� �ּҸ� �������� �ʰ�(binding ���� �ʰ�), ������ ����� �� �ּҸ� ������.
	//�����Լ� : static binding ��.
	//�����Լ� : dynamic binding ��.
	
	//����Ÿ���� �����ɸ���.(�ּҸ� ã�� ������ �ڷ� �̷���� ������)

	//�Լ��� virtual�� �����ϸ�, ��ĳ������ �Ǿ�����, �θ��� �ڷ����� ���󰡴°� �ƴ϶�
	//������ ����Ű�� ������ �ڷ����� ���󰡰� �ȴ�.
	//p->draw();
	MyShape* p;
	p = &b;
	p->draw();
	p = &c;
	p->draw();

	//���� �ٸ� ������Ÿ���� �ϳ��� �迭�� ���� ����.
	MyShape *arr[3];
	/*arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;*/
	arr[0] = new MyRect(20,30);
	arr[1] = new MyRect(10,20,3,3);
	arr[2] = new MyCircle(0,0,10);
	arr[2] = new MyLine(0,0,100,100);

	for (int i = 0; i < 3; i++) {
		arr[i]->draw();
	}

	//�ٿ�ĳ����(���� �� �Ⱦ�)
	//���� �θ� Ŭ�������� changeScale()���� �Լ��� ���� ���.
	MyCircle *cls = (MyCircle*)arr[2];
	//cls->m_radius = 100;
	//m_radius�� protected�� �ȵǴ� ����

	return 0;
}