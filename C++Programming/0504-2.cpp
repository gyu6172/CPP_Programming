#include <iostream>
using namespace std;

//���� ���� Ŭ������ ���ø����� ���� �� ������?
template <class T> /*�Ǵ�*/ /*template <typename T>*/
class MyArray {
private:
	T* m_pData;
	int m_size;
public:
	MyArray(int size)
	{
		m_size = size;
		m_pData = new T[m_size];
	}
	MyArray(MyArray& in) {
		//���� �����ڿ����� �Է� ���ڰ� ���� ������ Ȯ���ؾ� �Ѵ�.
		m_size = in.m_size;
		m_pData = new T[m_size];
		for (int i = 0; i < m_size; i++) {
			m_pData[i] = in[i];
		}
	}
	~MyArray() {
		delete[] m_pData;
	}
	T& operator[](int index) {
		return m_pData[index];
	}
	int getSize() { return m_size; }
};
//���ø��� ������ ��ü�� �̷����� ������(T�� ���� �𸣴ϱ�) ������� ��ƴ�.
//�׷��� ���ø��� ����Ͽ� ǥ�� ���̺귯���� ����� ���� ���� ����Ѵ�. : STL(Standard Template Library)
//���� ���� ����ϴ� STL 3����
#include <vector>
#include <list>
#include <deque>
int main() {

	MyArray<float> arr(10);		//Ŭ���������� ���ڷ� �ڷ����� �� �� ���� ������ <float>�� �� ���־�� �Ѵ�.
	for (int i = 0; i < arr.getSize(); i++) {
		arr[i] = i * 10 / 4.0f;
	}
	for (int i = 0; i < arr.getSize(); i++) {
		cout << i << ":" << arr[i] << endl;
	}
	
	vector<float> varr(10);
	for (int i = 0; i < varr.size(); i++) {
		varr[i] = i * 10;
	}
	for (int i = 0; i < varr.size(); i++) {
		cout << i << ":" << varr[i] << endl;
	}

	//���Ϳ� ũ�⸦ ���ټ��� �ִ�.
	vector<int> varr2;
	varr2.push_back(1);
	varr2.push_back(2);
	varr2.push_back(3);
	for (int i = 0; i < varr2.size(); i++) {
		cout << i << ":" << varr2[i] << endl;
	}

	list<int> larr;
	larr.push_back(10);
	larr.push_back(20);
	larr.push_back(30);
	larr.push_back(40);
	larr.push_back(50);
	//larr[1]�� �ȵȴ�. larr.at(1)���� �ȵȴ�.
	//list�� Ž���Ҷ��� iterator�� ����Ѵ�.
	//list�� ����ϴ� ������ ���� �� Ư�� �ε����� ���� �̾Ƴ��°� �ƴ϶�, ��ü�� ���� �� ����Ѵ�.

	//iteraor : list�� ���Ҹ� ����Ű�� ��ȸ�� �����ͺ���
	list<int>::iterator iter = larr.begin();	
	//larr.end : ������ ��� ������ �ִٰ� �����ϸ� �ɵ�?
	while (iter != larr.end()) {
		cout << (*iter) << endl;
		iter++;
	}

	//larr.remove(30) : 30�̶�� �����͸� ����
	//larr.erase(iter) : iter�� ����Ű�� �����͸� ����
	//iterator�� ������ ���� �����ϰ� ���� iterator�� �� ���� �Ұ� �ȴٴ� ���� ��������.
	
	//auto : ����Ÿ���� ��Ȯ�� ��쿡 ����Ѵ�. �׷��� autoŰ���带 ���. ��, iterator�� �ڷ����� list�� �ڷ����� ����.
	auto it = larr.begin();
	
}