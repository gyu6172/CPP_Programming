#include <iostream>
using namespace std;
class MyClass{
private:
	int data;
	MyClass();
public:
	MyClass(int x) {
		data = x;
	}

	MyClass operator+(int n);
	friend MyClass operator+(int n, MyClass in);
};

MyClass operator+(int n, MyClass in) {
	in.data
}	


int main() {
	MyClass a(10);
	MyClass b(20);
}