#include <iostream>
using namespace std;
int main() {
	int i,j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			cout<<j<<"X"<<i<<"="<<j * i<<"\t";
		}
		cout<<endl;
	}
}