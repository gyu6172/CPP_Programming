#include <iostream>
using namespace std;
int main() {
	double a,b,c,d,e;
	cout<<"5 ���� �Ǽ��� �Է��϶�>>";
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;

	double max=a;
	if (max < b)	max = b;
	else if (max < c)	max = c;
	else if (max < d)	max = d;
	else if (max < e)	max = e;

	cout<<"���� ū �� = "<<max<<endl;

	



}