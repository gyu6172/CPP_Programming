#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Random {
private:
public:
	Random(){ srand(time(NULL)); }
	int next();
	int nextInRange(int st, int ed);
};
int Random::next() {
	return rand();
}
int Random::nextInRange(int st, int ed)
{
	int n = rand()%(ed-st+1);
	n += st;
	return n;
}
int main() {
	Random r;

	cout<<"--0���� "<<RAND_MAX<<"������ ���� ���� 10��--"<<endl;
	for (int i = 0; i < 10; i++) {
		int n=r.next();
		cout<<n<<" ";
	}
	cout<<endl<<endl<<"--2���� "<<"4 ������ �������� 10��--"<<endl;
	for (int i = 0; i < 10; i++) {
		int n=r.nextInRange(2,4);
		cout<<n<<' ';
	}
	cout<<endl;
	return 0;




}