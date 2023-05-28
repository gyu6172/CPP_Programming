#include <iostream>
#include <string>
using namespace std;
class Histogram {
private:
	static int m_alphabet_arr[26];
	static int m_alphabet_cnt;
	int getNum(char c);
	void updateArr(string str);
public:
	Histogram() {

	}
	Histogram(string str) {
		cout<<str<<endl;
		updateArr(str);
	}
	void put(string str);
	void print();
};

int Histogram::m_alphabet_arr[26] = {0,};
int Histogram::m_alphabet_cnt = 0;

int main() {
	Histogram histo("Sejong University");
	histo.put("Software Department");
	histo.put("Midterm programming");
	histo.print();

	return 0;
}

int Histogram::getNum(char c)
{
	if ('a' <= c && c <= 'z') {
		return c-'a';
	}
	else if('A'<=c && c<='Z'){
		return c-'A';
	}
}

void Histogram::updateArr(string str)
{
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			m_alphabet_arr[getNum(str[i])]++;
			m_alphabet_cnt++;
		}
	}
}

void Histogram::put(string str)
{
	cout<<str<<endl;
	updateArr(str);
}

void Histogram::print()
{
	cout<<"ÃÑ ¾ËÆÄºª ±ÛÀÚ¼ö: "<<m_alphabet_cnt<<endl;
	for (int i = 0; i < 26; i++) {
		cout<<(char)('a'+i)<<"("<<m_alphabet_arr[i]<<") :";
		for (int j = 0; j < m_alphabet_arr[i]; j++) {
			cout<<"*";
		}
		cout<<endl;
	}
}
