#include <iostream>
#include <string>
using namespace std;
class Date {
private:
	int m_year, m_month, m_day;

public:
	Date(int year, int month, int day);
	Date(string date);
	int getYear();
	int getMonth();
	int getDay();
	void show();
};

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout<<birth.getYear()<<","<<birth.getMonth()<<","<<birth.getDay()<<endl;	
}

Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

Date::Date(string date)
{
	string str="";
	int year,month,day;
	int flag=0;
	for (int i = 0; i < date.length(); i++) {
		if (date[i] == '/') {
			if (flag == 0) {
				flag++;
				year = stoi(str);
				str="";
			}
			else if (flag == 1) {
				flag++;
				month = stoi(str);
				str = "";
			}
		}
		else {
			str += date[i];
		}
	}
	if (flag == 2) {
		day = stoi(str);
		str = "";
	}
	m_year = year;
	m_month = month;
	m_day = day;
}

int Date::getYear()
{
	return m_year;
}

int Date::getMonth()
{
	return m_month;
}

int Date::getDay()
{
	return m_day;
}

void Date::show()
{
	cout<<getYear()<<"³â"<<getMonth()<<"¿ù"<<getDay()<<"ÀÏ"<<endl;
}
