#include <iostream>
#include <string>
using namespace std;
class CBook {
private:
	char *title;
	int price;
	int getLength(const char* str) {
		int len=0;
		for (int i = 0; str[i] != NULL; i++) {
			len++;
		}
		return len;
	}
public:
	CBook(const char* str, int p)
	{	
		title = new char[getLength(str)+1];
		int i=0;
		for (; i < getLength(str); i++) {
			title[i] = str[i];
		}
		title[i] = '\0';
		price = p;
	}
	CBook(CBook& in) {
		if (in.title == this->title) {
			return;
		}
		title = new char[getLength(in.title) + 1];
		int i = 0;
		for (; i < getLength(in.title); i++) {
			title[i] = in.title[i];
		}
		title[i] = '\0';
		price = in.price;
	}

	void set(const char* str, int p) {
		delete title;
		title = new char[getLength(str) + 1];
		int i = 0;
		for (; i < getLength(str); i++) {
			title[i] = str[i];
		}
		title[i] = '\0';
		price = p;
	}
	
	void show() {
		cout<<title<<": "<<price<<"원"<<endl;
	}
};

int main() {
	CBook cpp("명품C++", 10000);
	CBook java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}
