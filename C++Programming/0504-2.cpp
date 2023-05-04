#include <iostream>
using namespace std;

//내가 만든 클래스도 템플릿으로 만들 수 있을까?
template <class T> /*또는*/ /*template <typename T>*/
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
		//복사 생성자에서는 입력 인자가 나랑 같은지 확인해야 한다.
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
//템플릿은 컴파일 자체가 미뤄지기 때문에(T가 뭔지 모르니까) 디버깅이 어렵다.
//그래서 템플릿을 사용하여 표준 라이브러리를 만들어 놓은 것을 사용한다. : STL(Standard Template Library)
//가장 많이 사용하는 STL 3대장
#include <vector>
#include <list>
#include <deque>
int main() {

	MyArray<float> arr(10);		//클래스에서는 인자로 자료형을 알 수 없기 때문에 <float>를 꼭 써주어야 한다.
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

	//벡터에 크기를 안줄수도 있다.
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
	//larr[1]는 안된다. larr.at(1)또한 안된다.
	//list를 탐색할때는 iterator를 사용한다.
	//list를 사용하는 이유는 원할 때 특정 인덱스의 값을 뽑아내는게 아니라, 전체를 훑을 때 사용한다.

	//iteraor : list의 원소를 가리키는 순회용 포인터변수
	list<int>::iterator iter = larr.begin();	
	//larr.end : 마지막 노드 다음에 있다고 생각하면 될듯?
	while (iter != larr.end()) {
		cout << (*iter) << endl;
		iter++;
	}

	//larr.remove(30) : 30이라는 데이터를 지움
	//larr.erase(iter) : iter가 가리키는 데이터를 지움
	//iterator로 삭제할 때는 삭제하고 나서 iterator가 갈 길을 잃게 된다는 것을 생각하자.
	
	//auto : 리턴타입이 명확한 경우에 사용한다. 그럴때 auto키워드를 사용. 즉, iterator의 자료형의 list의 자료형을 따라감.
	auto it = larr.begin();
	
}