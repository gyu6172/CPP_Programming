#include "MyMemoApp0502.h"
#include <iostream>

MyMemoApp0502::MyMemoApp0502(std::string name) : MyApp0502(name) {

}

void MyMemoApp0502::initInstance() {
	std::cout << "Init: MyMemoApp" << std::endl;
}
void MyMemoApp0502::run() {
	std::cout << "Writing Memo!!" << std::endl;
}
void MyMemoApp0502::exitInstance() {
	std::cout << "Exit: MyMemoApp" << std::endl;
}