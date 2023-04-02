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
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
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
	cout<<"�˻��ϰ��� �ϴ� ���� �̸� >> ";
	string name;
	cin>>name;
	for (Circle* c = p; c < p + size; c++) {
		if (c->getName() == name) {
			cout<<c->getName()<<"�� ������ "<<c->getArea()<<endl;
		}
	}
}

void CircleManager::searchByArea()
{	cout<<"�ּ� ������ ������ �Է��ϼ��� >> ";
	int minArea;
	cin>>minArea;
	cout<<minArea<<"���� ū ���� �˻��մϴ�."<<endl;
	for (Circle* c = p; c < p + size; c++) {
		if (c->getArea() > minArea) {
			cout<<c->getName()<<"�� ������ "<<c->getArea()<<",";
		}
	}
}

int main() {
	
	cout<<"���� ���� >> ";
	
	int n;
	cin>>n;

	CircleManager circleManager(n);

	circleManager.searchByName();
	circleManager.searchByArea();

	return 0;
}