#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myCompare(int a, int b) {
	return (a > b);
}

int main() {
	vector<int> arr;

	//srand(time(NULL));
	for (int i = 0; i < 10; i++ ) {
		arr.push_back(rand()%100);
	}
	/*for (int i = 0; i<arr.size(); i++) {
		cout << arr[i] <<", ";
	}
	cout << endl;
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;*/

	//myCompare()함수가 true가 나오는 방향으로 된다.
	sort(arr.begin(), arr.end(), myCompare);

	//for-each문 (읽기 전용)
	for (auto e : arr) {
		cout << e <<", ";
		//값을 바꾸고 싶으면 e를 레퍼런스로 선언한다.
	}
	cout << endl;
	
	
}