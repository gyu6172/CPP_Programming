#include <iostream>
using namespace std;
class Histogram {
private:
	static int char_arr[26];
	static int char_cnt;
	int getIndex(char c);
	bool isChar(char c) {
		if (('a'<=c && c<='z') || ('A'<=c && c<='Z')) {
			return true;
		}
		else
			return false;
	}
public:
	Histogram(string str)
	{
		cout<<str<<endl;
		for (int i = 0; i < str.length(); i++) {
			if (isChar(str[i])) {
				char_arr[getIndex(str[i])] += 1;
				char_cnt++;
			}
		}
	}
	void put(string str);
	void print();
};
int Histogram::getIndex(char c) {
	if ('a' <= c && c <= 'z') {
		return c-'a';
	}
	else {
		return c-'A';
	}
}
void Histogram::put(string str) {
	cout<<str<<endl;
	for (int i = 0; i < str.length(); i++) {
		if (isChar(str[i])) {
			char_arr[getIndex(str[i])] += 1;
			char_cnt++;
		}
	}
}

void Histogram::print() {
	cout<<"ÃÑ ¾ËÆÄºª ±ÛÀÚ¼ö: "<<char_cnt<<endl;
	for (int i = 0; i < 26; i++) {
		cout<<(char)('a'+i)<<"("<<char_arr[i]<<") : ";
		for (int j = 0; j < char_arr[i]; j++) {
			cout<<"*";
		}
		cout<<endl;
	}
}

int Histogram::char_arr[26] = {0};
int Histogram::char_cnt = 0;

int main() {
	Histogram histo("Sejong University");
	histo.put("Software Department");
	histo.put("Midterm programming");
	histo.print();
}