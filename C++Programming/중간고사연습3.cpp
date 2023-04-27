#include <iostream>
#include <string>
using namespace std;
class Person {
private:
	string name;
	int age;
	static int id;
public:
	Person(){cout<<"�⺻ ������ ȣ��"<<endl; id++;}
	Person(string name, int age);
	Person(Person& in);
	~Person();
	void printInfo();
	string getName();
	void setName(string name);
};

Person::Person(string name, int age) {
	cout<<"�Ű����� ������ ȣ��"<<endl;
	id++;
	this->name = name;
	this->age = age;
}
Person::Person(Person& in) {
	cout<<in.name<<"�� �����ϴ� ������ ȣ��"<<endl;
	id++;
	name = in.name;
	age = in.age;
}
Person::~Person() {
	cout<<name<<"�Ҹ��� ȣ��"<<endl;
	id--;
}
void Person::printInfo() {
	cout<<"�̸� : "<<name<<", ���� : "<<age<<", id : "<<id << endl;
}
string Person::getName() {
	return name;
}
void Person::setName(string name) {
	this->name = name
}

void printName(Person in) {
	cout<<"�̸��� "<<in.getName()<<"�Դϴ�."<<endl;
}
int Person::id = 0;
int main() {

	Person a("kim",12);
	Person b = a;
	a.printInfo();
	a.setName("Lee");
	b.printInfo();

	printName(b);

	//Person arr[3] = {Person("a",1),Person("b",2),Person("c",3)};	

	return 0;
}