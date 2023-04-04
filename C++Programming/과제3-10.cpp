#include <iostream>
#include <string>
using namespace std;
class Person {
private:
	string name;

public:
	Person(){}
	Person(string name){this->name = name;}
	string getName(){return name;}
	void setName(string name){this->name = name;}
};

class Family {
private:
	string familyName;
	Person *p;
	int size;
public:

	Family(string name, int size);
	void show();
	void setName(int n, string name);
	~Family();
};

Family::Family(string name, int size)
{
	familyName = name;
	this->size = size;
	p = new Person[this->size];
}

void Family::show()
{
	cout<<familyName<<"가족은 다음과 같이 "<<size<<"명 입니다."<<endl;
	for (int i = 0; i < size; i++) {
		cout<<p[i].getName()<<"\t";
	}
	cout<<endl;
}

void Family::setName(int n, string name)
{
	p[n].setName(name);
}

Family::~Family()
{
	delete[] p;
}

int main() {
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();

	delete simpson;
}