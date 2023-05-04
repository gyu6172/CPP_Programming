#include <iostream>
using namespace std;

//int밖에 안된다ㅠㅠ
//void mySwap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//함수 오버로딩을 사용하여 자료형이 float, double, char, string...일 때 작동하는 함수를 만들 수 있다.
//그런데 바꾸는 코드는 비슷한데 굳이 함수를 여러개 만들 필요가 있을까?
//그래서 template이라는게 나왔다.
template <class T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
//템플릿은 컴파일 단계에서 코드를 추가하지 않고 실행 단계에서 추가한다.

template<class T>
bool isBig(T a, T b) {
	if (a > b) return true;
	else return false;
}
//내가 만든 클래스도 템플릿으로 만들 수 있을까?
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
	mySwap/*<int>*/(a, b);	//입력 인자를 보고 자료형을 알 수 있다. 따라서 <int>는 생략 가능

	string c = "sejong";
	string d = "university";
	mySwap/*<string>*/(c, d);

	cout << "a=" << a << ", b="<< b << endl;
	cout << "c=" << c << ", d="<< d << endl;
	cout << "bigger is " << (isBig(a, b)? "a" : "B") << endl;

}