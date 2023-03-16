#include <iostream>
#include <string>
using namespace std;
int main() {
	cout<<"5 명의 이름을 ;로 구분하여 입력하세요"<<endl;
	string str;
	string longStr="";
	string nowStr="";
	getline(cin, str);
	int i,j;
	int cnt=1;
	for (i = 0; i < str.length(); i++) {
		if (str[i] == ';') {
			if (longStr.length() < nowStr.length()) {
				longStr = nowStr;
			}
			cout<<cnt<<" : "<<nowStr<<endl;
			nowStr="";
			cnt++;
		}
		else {
			nowStr += str[i];
		}
	}
	cout<<"가장 긴 이름은 "<<longStr<<endl;


}