#include <iostream>
//string 클래스 사용하기 위한 헤더파일 추가
#include <cstring>
#include <string>

using namespace std;

int main(){
	//문자열 연산
	string s1="Sejong";
	s1 += " university";
	cout<<s1<<endl;
	
	//문자열 복사
	string s2 = s1;
	s2 += " software";
	cout<<s2<<endl;

	//문자열 비교
	string st1="hello";
	string st2="hello";
	if (st1 == st2) {
		cout<<"same"<<endl;
	}
	else {
		cout<<"different"<<endl;
	}

	//string변수에 배열 값을 대입하기
	string str1;
	char str2[10]="hello";
	str1 = str2;
	cout<<"str1 : "<<str1<<endl;

	//배열에 string값을 대입하기
	char a[100];
	string b="hello";
	strcpy_s(a,b.c_str());
	cout<<"a : "<<a<<endl;

	//공백 포함하여 한 줄 통째로 입력받기
	string temp;
	getline(cin, temp);
	cout<<temp<<endl;

	return 0;
}