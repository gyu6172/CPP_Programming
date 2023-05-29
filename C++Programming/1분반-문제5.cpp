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
	CBoard::add("�߰���� �ǽ� ��");
	CBoard::add("�� 5����");
	CBoard::print();
	CBoard::add("���������� ���� ���ô�.");
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
	cout<<"****�Խ����Դϴ�.****"<<endl;
	for (int i = 0; i < m_text_cnt; i++) {
		cout<<m_texts[i]<<endl;
	}
}
