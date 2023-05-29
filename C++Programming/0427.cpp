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
	//함수 구현을 미룰 수 있다.
	//이런 함수를 순수 가상함수, 또는 추상함수 라고 한다.
	//함수가 있으나 구현을 미뤘다는 뜻이다.
	//virtual void firstClick(float x, float y) = 0;	<--구현 무조건 해야함
	//virtual void dragging(float x, float y){};		<--구현 해도 되고 안해도 됨
	//virtual void endClick(float x, float y){};

	//추상 함수를 갖는 클래스를 추상 클래스(abstract class)라고 한다.
	//추상 클래스는 객체를 못 만듬. 즉 부모로만 활동하겠다.
	//추상 클래스를 상속받는 클래스에서 함수 오버라이딩을 강제한다.
	virtual void draw() = 0;
	/*{
		cout<<"[SHAP] ("<<m_x<<", "<<m_y<<")"<<endl;
	}*/
};

class MyRect : public MyShape{
//내가 갖고 있는 멤버변수만 신경쓰자.
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
		//보통 오버라이딩은 부모가 갖고있는거 먼저 하고 자식꺼는 내가 한다. 이게 맞음
		//MyShape::draw();
		//그런데 두 줄이 출력되면 안이쁘니까 이번에만 부모 클래스의 멤버변수를 protected로 하자.
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
	//종류가 다른 클래스를 같은 배열에 넣을 수 있을까?
	//MyShape a(20,30);
	MyRect b(10,20,3,3);
	MyCircle c(0,0,10);

	//멤버함수는 기본적으로 데이터타입을 따라간다.
	//즉, 부모의 draw() 호출한다.

	//함수도 역시 메모리(주소값)가 있다.
	//MyShape* p = &a;
	//컴파일러 : 아 p는 MyShape구나. draw()는 여기에 적혀있지.
	//컴파일러는 컴파일타임에 함수의 주소를 저장함.
	//그런데 주소를 미리 저장하지 말자고 하는 문법이 있다.(나중에 찾자) : virtual 키워드
	//virtual 함수는 나중에 오버라이딩 될 가능성이 있다는 뜻.
	//binding : 함수 이름과 주소를 매칭하는 것.
	//virtual함수는 컴파일단계에서 주소를 지정하지 않고(binding 하지 않고), 구문이 실행될 때 주소를 지정함.
	//정적함수 : static binding 됨.
	//가상함수 : dynamic binding 됨.
	
	//실행타임이 오래걸린다.(주소를 찾는 과정을 뒤로 미뤄놨기 때문에)

	//함수를 virtual로 선언하면, 업캐스팅이 되었을때, 부모의 자료형을 따라가는게 아니라
	//실제로 가리키는 변수의 자료형을 따라가게 된다.
	//p->draw();
	MyShape* p;
	p = &b;
	p->draw();
	p = &c;
	p->draw();

	//각기 다른 데이터타입을 하나의 배열로 관리 가능.
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

	//다운캐스팅(보통 잘 안씀)
	//보통 부모 클래스에서 changeScale()같은 함수를 만들어서 사용.
	MyCircle *cls = (MyCircle*)arr[2];
	//cls->m_radius = 100;
	//m_radius가 protected라 안되는 거임

	return 0;
}