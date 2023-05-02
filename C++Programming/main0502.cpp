#include <iostream>
using namespace std;

#include "MyDrawApp0502.h"
#include "MyMemoApp0502.h"

int main() {
	
	MyApp0502::addApp(new MyMemoApp0502("memo1"));
	MyApp0502::addApp(new MyDrawApp0502("draw1"));
	MyApp0502::addApp(new MyMemoApp0502("memo2"));

	MyApp0502::runAll();


	return 0;
}