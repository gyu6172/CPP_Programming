#include <iostream>

using namespace std;

int main() {
	int a=10;

	//std에 있는 cout을 사용하겠다.
	//"Hello"와 "World"와 a를 cout에 보낸다.
	cout<<"Hello"<<" World"<<a<<endl;


	//cin과 cout은 자료형을 신경쓰지 않는다.
	int b;
	cout<<"Input"<<endl;
	cin>>b;
	cout<<b;
	


	return 0;
}