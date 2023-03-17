#include <iostream>
using namespace std;
int main() {

	double arr[5];
	cout<<"5 개의 실수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin>>arr[i];
	}
	double max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout<<"제일 큰 수 = "<<max<<endl;

}