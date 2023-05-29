#include <iostream>
using namespace std;

class CFamily {
private:
	int m_person_cnt;
	string m_family_name;
	string* m_persons;

public:
	CFamily(const char* name, int size)
	{
		m_family_name = name;
		m_person_cnt = size;
		m_persons = new string[m_person_cnt];
	}
	void setName(int idx, const char* name) {
		m_persons[idx] = name;
	}
	void show() {
		cout<<m_family_name<<"의 가족은 "<<m_person_cnt<<"명입니다."<<endl;
		for (int i = 0; i < m_person_cnt; i++) {
			cout<<m_persons[i]<<endl;
		}
	}
};

int main() {
	CFamily simpson("Simpson", 3);
	simpson.setName(0, "Mr. Simpson");
	simpson.setName(1, "Mrs. Simpson");
	simpson.setName(2, "Bart Simpson");
	simpson.show();


}