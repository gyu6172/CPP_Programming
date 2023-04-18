#include <iostream>
#include <string>
using namespace std;
class Person {
private:
	string name;
	int age;
	string gender;
	int grade;
public:
	static int id;
	Person() {
		cout<<"�⺻ ������ ȣ��"<<endl;
		grade = id;
		id++;
	}
	Person(string name, int age, string gender) {
		cout<<"�Ű����� ������ ȣ��"<<endl;
		this->grade = id++;
		this->name = name;
		this->age = age;
		this->gender = gender;
	}
	Person(Person& in) {
		cout<<"���� ������ ȣ��"<<endl;
		id++;
		this->grade = id++;
		this->name = in.name;
		this->age = in.age;
		this->gender = in.gender;
	}
	~Person() {
		cout<<name<<"�Ҹ�"<<endl;
	}
	string getName(){return name;}
	int getAge(){return age;}
	string getGender(){return gender;}
	int getGrade() {return grade;}
	void setName(string name){this->name = name;}
	void setAge(int age){this->age = age;}
	void setGender(string gender){this->gender = gender;}
	void print();

	static int getId() {
		return id;
	}

	friend void func2(Person p);
};

void func2(Person p) {
	cout<<p.name<<endl;
}

int Person::id = 0;

void Person::print() {
	cout << "�̸� : " << name << ", ���� : " << age << ", ���� : " << gender << ", id : "<<grade<<endl;
}

void func(Person in) {
	in.print();
}

int main() {
	Person a("ȫ�浿", 20, "����");
	Person b(a);
	Person c;
	c = a;
	a.print();
	b.print();
	c.print();
	func(a);
	func(b);
	func(c);

	cout<<Person::getId()<<endl;
}