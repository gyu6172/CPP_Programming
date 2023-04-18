#include <iostream>
using namespace std;
class MyComplex {
private:
	float m_real, m_img;

public:
	MyComplex(float r=0, float i=0){
		m_real = r;
		m_img = i;
	}
	void print();
	MyComplex operator+(MyComplex in);
	MyComplex operator-(MyComplex in);
	MyComplex operator*(MyComplex in);
	MyComplex operator*(float in);
	bool operator==(MyComplex in);
	MyComplex operator+=(MyComplex in);
	MyComplex operator!();
	float operator[](int idx);
	friend MyComplex operator++(MyComplex &in);

	friend MyComplex operator*(float lhs, MyComplex rhs);
	friend ostream& operator<<(ostream& o, MyComplex in);
};
ostream& operator<<(ostream& o, MyComplex in) {
	o<< in.m_real << ((in.m_img >= 0) ? "+" : "") << in.m_img << "i";
	return o;
}
MyComplex operator++(MyComplex &in) {
	in.m_real++;
	in.m_img++;
	return in;
}
MyComplex operator*(float lhs, MyComplex rhs) {
	MyComplex out;
	out.m_real = lhs * rhs.m_real;
	out.m_img = lhs * rhs.m_img;
	return out;
}
void MyComplex::print() {
	cout<<m_real<<((m_img>=0)?"+":"")<< m_img << "i" << endl;
}
MyComplex MyComplex::operator+(MyComplex in) {
	MyComplex out;
	out.m_real = m_real + in.m_real;
	out.m_img += m_img + in.m_img;
	return out;
}
MyComplex MyComplex::operator-(MyComplex in) {
	MyComplex out;
	out.m_real = m_real - in.m_real;
	out.m_img += m_img - in.m_img;
	return out;
}
MyComplex MyComplex::operator*(MyComplex in) {
	MyComplex out;
	out.m_real = m_real * in.m_real - m_img * in.m_img;
	out.m_img = m_real * in.m_img + m_img * in.m_real;
	return out;
}
MyComplex MyComplex::operator*(float in) {
	MyComplex out;
	out.m_real = m_real*in;
	out.m_img = m_img*in;
	return out;
}
bool MyComplex::operator==(MyComplex in) {
	if (m_real == in.m_real && m_img == in.m_img) {
		return true;
	}
	else {
		return false;
	}
}
MyComplex MyComplex::operator+=(MyComplex in) {
	m_real += in.m_real;
	m_img += in.m_img;
	return *this;
}
MyComplex MyComplex::operator!()
{
	MyComplex out;
	out.m_real = m_real;
	out.m_img = -m_img;
	return out;
}
float MyComplex::operator[](int idx)
{
	if (idx == 0) {return m_real;}
	if(idx==1){return m_img;}
	return 0.0f;
}
int main() {
	//MyComplex a(1,3), b(1,5);

	//a.print();
	//b.print();

	//MyComplex c = a+b;
	//c.print();

	//MyComplex d = a+b+c;
	//d.print();

	//MyComplex e = a+b-c;
	//e.print();

	//MyComplex f = a*b;
	//f.print();

	//MyComplex g = a*3;
	//g.print();

	//MyComplex h = 3 * (a+b) + c;
	//h.print();

	//MyComplex i = a+=b;
	//i.print();
	//a.print();

	//MyComplex j = b*(!b);
	//j.print();

	//MyComplex k = a;	//copy constructor
	//k = a;				//assignment operator

	//a.print();
	//cout<<a<<endl;
	//
	//cout<<a[0]<<"+" << a[1] << "i" << endl;

	MyComplex a(1,2), b(5,3);
	MyComplex c = a++;
	MyComplex d = ++a;

	a.print();
	b.print();
	c.print();
	d.print();

	return 0;
}