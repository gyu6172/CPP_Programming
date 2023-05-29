#include <iostream>
using namespace std;

class MyVector {
private:
	int m_x,m_y,m_z,m_w;

public:
	MyVector(){}
	MyVector(int x, int y, int z, int w){
		m_x = x;
		m_y = y;
		m_z = z;
		m_w = w;
	}

	MyVector operator+(MyVector& in);
	MyVector& operator+=(MyVector& in);
	friend ostream& operator<<(ostream& o, MyVector& in);
};

MyVector MyVector::operator+(MyVector& in)
{
	MyVector tmp;
	tmp.m_x = this->m_x + in.m_x;
	tmp.m_y = this->m_y + in.m_y;
	tmp.m_z = this->m_z + in.m_z;
	tmp.m_w = this->m_w + in.m_w;
	return tmp;
}

MyVector& MyVector::operator+=(MyVector& in)
{
	this->m_x += in.m_x;
	this->m_y += in.m_y;
	this->m_z += in.m_z;
	this->m_w += in.m_w;
	return (*this);
}

ostream& operator<<(ostream& o, MyVector& in) {
	o<<"( "<<in.m_x<<" "<<in.m_y<<" "<<in.m_z<<" "<<in.m_w<<" )";
	return o;
}

int main() {
	MyVector a(1,2,3,4), b(2,3,4,5), c;
	c = a+b;
	a += b;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}