#include "MyDrawApp0502.h"
#include <iostream>

MyDrawApp0502::MyDrawApp0502(std::string name) : MyApp0502(name){

}

void MyDrawApp0502::initInstance() {
	std::cout<<"Init: MyDrawApp"<<std::endl;
}
void MyDrawApp0502::run() {
	std::cout<<"Drawing!!"<<std::endl;
}
void MyDrawApp0502::exitInstance() {
	std::cout<<"Exit: MyDrawApp"<<std::endl;
}