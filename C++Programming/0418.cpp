#include <iostream>
#include <string>

using namespace std;

class MyPos {
//private : 클래스 외부에서 접근 불가(상속받아도 접근 불가)
//protected : 클래스 외부에서 접근 불가(상속받으면 가능)
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

//public에 뜻이 있는 건 아니다. 그냥 문법이 그러하다.
class MyColorPos : public MyPos{
private:
	string m_color;

public:
	MyColorPos()/*클래스의 변수에 다른 클래스가 있는 경우, 이 부분에서 그 클래스의 생성자가 호출된다.
	부모클래스의 기본생성자 또한 여기서 불러진다. 기본 생성자가 없는 경우 컴파일 에러
	*/:MyPos(0,0), m_color("black") {
		//부모에서 만든 변수는 부모에서 관리한다.
		//우리 자식 클래스에서는 자식에서 만든 변수만 관리하자.
		m_color = "black";
	}	
	MyColorPos(float x, float y, string c) :MyPos(x, y), m_color(c) {
		
	}
	~MyColorPos() {
		//추가된 거 정리하고, 나머지거 정리하고,(스택?)
		//부모꺼는 부모가 신경쓴다. 자식꺼는 자식이 신경쓴다.
		cout<<"MyColorPos Destructor called!"<<endl;
	}
	void print() {		//함수 오버라이딩(function overriding) : 자식 클래스에서 부모 클래스의 기능을 바꾼다.
						//오버라이딩은 함수를 통째로 바꿔치기가 기본 기능이지만, 부모 함수의 기능에 내꺼를 더 추가하고 싶을때가 많다.
						
		MyPos::print();
		//m_x와 m_y는 private이라서 자식 클래스에서도 접근하지 못함.
		cout<<"color = "<<m_color<<endl;
	}
};

//"상속은 확장이다." (자식은 부모보다 크다.)

int main() {
	
	//MyPos a(10,20);
	//a.print();

	////디폴트 생성자 만들기 때문에 가능
	//MyColorPos b;

	////불가능
	////MyColorPos b(10,20);
	//b.print();


	MyColorPos b(30,40,"red");
	MyPos a;
	//b객체는 a가 필요한 모든 요소를 가지고 있다. b로 a를 만드는 것 가능.
	//자식->부모, derived->base : "업캐스팅(상향 형변환)"
	//a = b;
	b.print();
	a.print();

	MyPos c(10,20);
	//반대는 안된다.
	//부모->자식, base->derived : "다운캐스팅(햐향 형변환)"
	//MyColorPos d = c;

	MyPos *p1;
	p1 = &b;		//포인터 업캐스팅(가능)
	p1->print();	//포인터의 데이터 타입이 우선이다. 즉, 부모의 print() 호출

	MyColorPos *p2;
	//p2 = &a;		//포인터 다운캐스팅(불가능)

	p2 = (MyColorPos*)p1;		//이건 된다.(???)
	p2->print();	//자식의 print()호출

	return 0;
}