#include <iostream>
//string Ŭ���� ����ϱ� ���� ������� �߰�
#include <cstring>
#include <string>

using namespace std;

int main(){
	//���ڿ� ����
	string s1="Sejong";
	s1 += " university";
	cout<<s1<<endl;
	
	//���ڿ� ����
	string s2 = s1;
	s2 += " software";
	cout<<s2<<endl;

	//���ڿ� ��
	string st1="hello";
	string st2="hello";
	if (st1 == st2) {
		cout<<"same"<<endl;
	}
	else {
		cout<<"different"<<endl;
	}

	//string������ �迭 ���� �����ϱ�
	string str1;
	char str2[10]="hello";
	str1 = str2;
	cout<<"str1 : "<<str1<<endl;

	//�迭�� string���� �����ϱ�
	char a[100];
	string b="hello";
	strcpy_s(a,b.c_str());
	cout<<"a : "<<a<<endl;

	//���� �����Ͽ� �� �� ��°�� �Է¹ޱ�
	string temp;
	getline(cin, temp);
	cout<<temp<<endl;

	return 0;
}