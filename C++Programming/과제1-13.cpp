#include <iostream>
using namespace std;
int main() {
	while (1) {
		cout << "? ";
		int n1, n2;
		char c;
		cin >> n1;
		cin >> c;
		cin >> n2;
		cout << n1 << " " << c << " " << n2 << " = ";
		if (c == '+') {
			cout << n1 + n2<<endl;
		}
		else if (c == '-') {
			cout << n1 - n2 << endl;
		}
		else if (c == '*') {
			cout << n1 * n2 << endl;
		}
		else if (c == '/') {
			cout << n1 / n2 << endl;
		}
		else if (c == '%') {
			cout << n1 % n2 << endl;
		}
	}
}