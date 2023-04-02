#include <iostream>
using namespace std;
class Circle {
private:
	int radius;
	string name;

public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};
void Circle::setCircle(string name, int radius)
{
	this->name = name;
	this->radius = radius;
}

double Circle::getArea()
{
	return 3.14 * this->radius * this->radius;
}

string Circle::getName()
{
	return this->name;
}


class CircleManager {
private:
	Circle* p;
	int size;

public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};
CircleManager::CircleManager(int size)
{
	this->size = size;
	p = new Circle[this->size];
	for (int i = 0; i < this->size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		string name;
		int radius;
		cin>>name;
		cin>>radius;
		(p+i)->setCircle(name, radius);
	}
}
CircleManager::~CircleManager()
{
	delete[] p;
}
void CircleManager::searchByName()
{
	cout<<"검색하고자 하는 원의 이름 >> ";
	string name;
	cin>>name;
	for (Circle* c = p; c < p + size; c++) {
		if (c->getName() == name) {
			cout<<c->getName()<<"의 면적은 "<<c->getArea()<<endl;
		}
	}
}

void CircleManager::searchByArea()
{	cout<<"최소 면적을 정수로 입력하세요 >> ";
	int minArea;
	cin>>minArea;
	cout<<minArea<<"보다 큰 원을 검색합니다."<<endl;
	for (Circle* c = p; c < p + size; c++) {
		if (c->getArea() > minArea) {
			cout<<c->getName()<<"의 면적은 "<<c->getArea()<<",";
		}
	}
}

int main() {
	
	cout<<"원의 개수 >> ";
	
	int n;
	cin>>n;

	CircleManager circleManager(n);

	circleManager.searchByName();
	circleManager.searchByArea();

	return 0;
}