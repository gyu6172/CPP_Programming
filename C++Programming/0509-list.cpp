#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class MyStudent {
private:
	int m_num;
	string m_name;

public:
	static int sortOrder;

	//�ɺ� ����. ��ġ #defineó��
	enum { NUM_ORDER = 0, NAME_ORDER };

	int getNum() { return m_num; }
	void setNum(int n) { m_num = n; }
	MyStudent(int num, string name)
	{
		m_num = num;
		m_name = name;
	}
	friend ostream& operator<<(ostream& o, MyStudent& in);
	friend bool compare1(MyStudent& a, MyStudent& b);
	friend bool compare2(MyStudent& a, MyStudent& b);
	friend bool compare(MyStudent& a, MyStudent& b);
};

int MyStudent::sortOrder = MyStudent::NUM_ORDER;

ostream& operator<<(ostream& o, MyStudent& in) {
	o << "[" << in.m_num << "] name:" << in.m_name;
	return o;
}

//num �������� ����
bool compare1(MyStudent& a, MyStudent& b) {
	return (a.m_num < b.m_num);
}

//name ������ ����
bool compare2(MyStudent& a, MyStudent& b) {
	return (a.m_name < b.m_name);
}

//�Ѵ�
bool compare(MyStudent& a, MyStudent& b) {
	switch (MyStudent::sortOrder)
	{
	case MyStudent::NUM_ORDER:
		return (a.m_num < b.m_num);
		break;

	case MyStudent::NAME_ORDER:
		return (a.m_name < b.m_name);
		break;

	default:
		break;
	}
}

int main() {
	
	list<MyStudent> arr;
	arr.push_back(MyStudent(100, "Kim"));
	arr.push_back(MyStudent(30, "Lee"));
	arr.push_back(MyStudent(50, "Kang"));
	arr.push_back(MyStudent(130, "Park"));
	arr.push_back(MyStudent(200, "Choi"));
	arr.push_back(MyStudent(80, "Yoon"));

	/*list<MyStudent>::iterator*/ auto it = arr.begin();
	//while (it != arr.end()) {
	//	auto prev_it = it;
	//	it++;
	//	if (prev_it->getNum() < 40) {
	//		arr.erase(prev_it);
	//		//���� ���� �����ؾ� �Ѵ�.
	//		//����� ������ iter�� �� ���� �Ҵ´�.
	//	}
	//}
	while (it != arr.end())
	{
		//erase()�Լ��� ������ ��� ���� ��带 �����Ѵ�.
		if (it->getNum() < 40) {
			it = arr.erase(it);
		}
		else {
			it++;
		}
	}

	MyStudent::sortOrder = MyStudent::NUM_ORDER;
	arr.sort(compare);

	for (auto e : arr) {
		cout << e << endl;
	}

	//remove(Mystudent in) : list�� in��ü�� �����.(==������ ���ǰ� �Ǿ��־���Ѵ�.)
	//unique() : �ߺ��� ��ü�� �����.
	
	
	

	

}