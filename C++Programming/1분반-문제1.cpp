#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	
	string rst = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		if(str[i]=='\\'){
			break;
		}
		rst += str[i];
	}
	for (int i = 0, j = rst.length() - 1; i < j; i++, j--) {
		char c = rst[i];
		rst[i] = rst[j];
		rst[j] = c;
	}
	cout<<rst;

}