#include <iostream>
using namespace std;
#include "MyPlace.h"

class MyBox {
private:
	int w, h;
public:
	MyBox(){
		w = 0;
		h = 0;
	}
	MyBox(int w, int h) {
		this->w = w;
		this->h = h;
	}
	~MyBox() {
		cout<<w<<"x"<<h<<"소멸"<<endl;
	}
	void print() {
		cout<<w<<"x"<<h<<"크기의 박스"<<endl;
	}
};
int main() {
	MyBox a(2,3);
	MyBox b(2,4);
	MyBox c;

	int n=2;
	MyBox **p = new MyBox*[n];
	for (int i = 0; i < n; i++) {
		p[i] = new MyBox(2,i);
		//p[i]->print();
	}

	for (int i = 0; i < n; i++) {
		delete p[i];
	}
	delete[] p;

	int m = 4;
	int cnt=1;
	MyBox ***arr = new MyBox**[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new MyBox*[m];
		for (int j = 0; j < m; j++) {
			arr[i][j] = new MyBox(i,j);
			cout<<cnt++<<"번째, ";
			arr[i][j]->print();
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		delete arr[i][j];
	//	}
	//	delete[] arr[i];
	//}
	//delete[] arr;
}