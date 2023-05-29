#include <iostream>
using namespace std;
class CBoard {
private:
	static int m_text_cnt;
	static string m_texts[10];
public:
	static void add(string str);
	static void print();
};

int CBoard::m_text_cnt=0;
string CBoard::m_texts[10] = {};

int main() {
	CBoard::add("중간고사 실시 중");
	CBoard::add("총 5문제");
	CBoard::print();
	CBoard::add("부정행위를 하지 맙시다.");
	CBoard::print();

	return 0;
}

void CBoard::add(string str)
{
	m_texts[m_text_cnt] = str;
	m_text_cnt++;
}

void CBoard::print()
{
	cout<<"****게시판입니다.****"<<endl;
	for (int i = 0; i < m_text_cnt; i++) {
		cout<<m_texts[i]<<endl;
	}
}
