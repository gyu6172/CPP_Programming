#include <iostream>
using namespace std;
#include "MyString0413.h"

int main() {
	MyString a("Sejong");
	MyString b = a;		//copy constructor �۵�
	MyString c;			//Assignment operator �۵�
	c = a;

	MyString d("Ultra");
	d.append(" ");		//MyString in = " "
	d.append(a);		//MyString in = a

	MyString e = "Software";
	MyString f;
	f = e + "department";

	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	cout<<f<<endl;


	return 0;
}