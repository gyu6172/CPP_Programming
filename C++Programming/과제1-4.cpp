#include <iostream>
using namespace std;
int main() {

	double arr[5];
	cout<<"5 ���� �Ǽ��� �Է��϶�>>";
	for (int i = 0; i < 5; i++) {
		cin>>arr[i];
	}
	double max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout<<"���� ū �� = "<<max<<endl;

}