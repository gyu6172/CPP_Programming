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
		//assert:������ �Լ�
		assert(r > 0);	//���� r<=0�̸� ���⼭ ����
		assert(c > 0);	//���� c<=0�̸� ���⼭ ����
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
	//���� delete�� ������ �ϴ°� ����������, nullptr�� ������.
	//�׷��� ���� ������ delete�� �� �ڿ� nullptr�� ���ش�.

	//�����Ҵ� �ϸ鼭 ������ �θ���(�̰� delete �Ҷ��� for������ ���� ��������)
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

	//���߹迭
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

	Box2D box(10,5);		//�ڱⰡ �˾Ƽ� �����Ҵ�, ������. smart Array ��� ��
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			box.setData(i,j,i*j);
		}
	}
	box.print();

	return 0;
}