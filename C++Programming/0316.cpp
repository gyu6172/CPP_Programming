#include <iostream>
using namespace std;
int main() {
	
	int a=10;		//0b0000 1010
	int b = 0b00010000;
	int c = a&b;	//0b0000 0000
	int d = a|b;	//0b0001 1010

	cout<<"a="<<a<<endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;



	return 0;
}