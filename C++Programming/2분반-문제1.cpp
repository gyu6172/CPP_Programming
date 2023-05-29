#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	string str_arr[100];
	int str_arr_iter=0;

	getline(cin, str);

	string tmp="";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ';') {
			str_arr[str_arr_iter] = tmp;
			str_arr_iter++;
			tmp="";
		}
		else {
			tmp += str[i];
		}
	}

	int max_length=0;
	int max_length_idx=0;
	for (int i = 0; i < str_arr_iter; i++) {
		cout<<i+1<<": "<<str_arr[i]<<endl;
		if (str_arr[i].length() > max_length) {
			max_length = str_arr[i].length();
			max_length_idx = i;
		}
	}

	cout<<"가장 긴 이름은 "<<str_arr[max_length_idx];
}