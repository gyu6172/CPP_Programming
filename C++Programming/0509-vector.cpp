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

	//myCompare()�Լ��� true�� ������ �������� �ȴ�.
	sort(arr.begin(), arr.end(), myCompare);

	//for-each�� (�б� ����)
	for (auto e : arr) {
		cout << e <<", ";
		//���� �ٲٰ� ������ e�� ���۷����� �����Ѵ�.
	}
	cout << endl;
	
	
}