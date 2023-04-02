#include <iostream>
using namespace std;
class Sample {
private:
	int *p;
	int size;

public:
	Sample(int n) {
		size = n;
		p = new int [n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read()
{
	for (int *ptr = p; ptr < p+size; ptr++) {
		cin>>*ptr;
	}
}

void Sample::write()
{
	for (int *ptr = p; ptr < p+size; ptr++) {
		cout<<*ptr<<" ";
	}
	cout<<endl;
}

int Sample::big()
{
	int max = *p;
	for (int* ptr = p; ptr < p + size; ptr++) {
		if (max < *ptr) {
			max = *ptr;
		}
	}
	return max;
}

Sample::~Sample()
{
	delete[] p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout<<"가장 큰 수는 "<<s.big()<<endl;

	return 0;
}
