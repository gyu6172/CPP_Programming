#include <iostream>
using namespace std;

//int�ۿ� �ȵȴ٤Ф�
//void mySwap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//�Լ� �����ε��� ����Ͽ� �ڷ����� float, double, char, string...�� �� �۵��ϴ� �Լ��� ���� �� �ִ�.
//�׷��� �ٲٴ� �ڵ�� ����ѵ� ���� �Լ��� ������ ���� �ʿ䰡 ������?
//�׷��� template�̶�°� ���Դ�.
template <class T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
//���ø��� ������ �ܰ迡�� �ڵ带 �߰����� �ʰ� ���� �ܰ迡�� �߰��Ѵ�.

template<class T>
bool isBig(T a, T b) {
	if (a > b) return true;
	else return false;
}
//���� ���� Ŭ������ ���ø����� ���� �� ������?
class MyIntArray {
private:
	int* m_pData;
	int m_size;
public:
	MyIntArray(int size)
	{
		m_size = size;
		m_pData = new int[m_size];
	}
	~MyIntArray() {
		delete[] m_pData;
	}
	int& operator[](int index) {
		return m_pData[index];
	}
	int getSize() {return m_size;}
};

int main() {
	int a = 10;
	int b = 20;
	mySwap/*<int>*/(a, b);	//�Է� ���ڸ� ���� �ڷ����� �� �� �ִ�. ���� <int>�� ���� ����

	string c = "sejong";
	string d = "university";
	mySwap/*<string>*/(c, d);

	cout << "a=" << a << ", b="<< b << endl;
	cout << "c=" << c << ", d="<< d << endl;
	cout << "bigger is " << (isBig(a, b)? "a" : "B") << endl;

}