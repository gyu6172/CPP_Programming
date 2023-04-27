#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

class Box2D{
private:
	int *m_data;
	int m_row;
	int m_col;
	int m_size;
public:
	Box2D(int r, int c){
		//assert:디버깅용 함수
		assert(r > 0);	//만약 r<=0이면 여기서 죽음
		assert(c > 0);	//만약 c<=0이면 여기서 죽음
		m_row = r;
		m_col = c;
		m_size = m_row*m_col;
		m_data = new int[m_size];
		for (int i = 0; i < m_size; i++) {
			m_data[i]=0;
		}
	}
	~Box2D() {
		delete[] m_data;
		m_data = nullptr;
	}
	void setData(int m, int n, int value) {
		assert(0<=m && m<m_row);
		assert(0<=n && n<m_col);
		int index = m*m_col + n;
		m_data[index] = value;
	}
	int getData(int m, int n) {
		assert(0 <= m && m < m_row);
		assert(0 <= n && n < m_col);
		int index = m * m_col + n;
		return m_data[index];
	}

	int &getRef(int m, int n) {
		assert(0 <= m && m < m_row);
		assert(0 <= n && n < m_col);
		int index = m * m_col + n;
		return m_data[index];
	}

	void print() {
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_col; j++) {
				cout<<getData(i,j)<<" ";
			}
			cout<<endl;
		}
	}
};

class Box {
private:
	int m_value;
public:
	Box(){ m_value=0; }
	Box(int v){ m_value = v; }
	void print() {
		cout<<"[Box] value = "<<m_value<<endl;
	}
};

void func(Box** in, int size) {
	for (int i = 0; i < size; i++) {
		in[i]->print();
	}
}
void func2(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout<<arr[i][j]<<endl;
		}
	}
}
int main() {
	//원래 delete를 여러번 하는건 위험하지만, nullptr은 괜찮다.
	//그래서 좋은 습관은 delete를 한 뒤에 nullptr로 해준다.

	//동적할당 하면서 생성자 부르기(이거 delete 할때는 for문으로 각각 지워야함)
	int num=10;
	Box **arr = new Box*[num];
	for (int i = 0; i < num; i++) {
		arr[i] = new Box(i);
		arr[i]->print();
	}

	Box* tmp = new Box[3];

	func(arr,num);

	for (int i = 0; i < num; i++) {
		delete arr[i];
	}
	delete[] arr;

	//이중배열
	//int arr2[10][5];
	int** arr2 = new int*[10];
	for (int i = 0; i < 10; i++) {
		arr2[i] = new int[5];
	}

	func2(arr2, 10, 5);

	for (int i = 0; i < 10; i++) {
		delete[] arr2[i];
	}
	delete[] arr2;

	Box2D box(10,5);		//자기가 알아서 동적할당, 삭제함. smart Array 라고 함
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			box.setData(i,j,i*j);
		}
	}
	box.print();

	return 0;
}