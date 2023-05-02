#include "MyApp0502.h"

MyApp0502* MyApp0502::head = nullptr;

MyApp0502::MyApp0502(std::string name) : m_name(name)
{
	m_pNext = nullptr;
}

void MyApp0502::start()
{
	initInstance();
	run();
	exitInstance();
}

MyApp0502* MyApp0502::getHead() {
	return head;
}

MyApp0502* MyApp0502::getTail()
{
	if (head == nullptr) return head;
	MyApp0502* tail = head;
	while (tail->m_pNext != nullptr) {
		tail = tail->m_pNext;
	}
	return tail;
}

void MyApp0502::addApp(MyApp0502* pApp)
{
	MyApp0502* tail = getTail();
	if (tail != nullptr) {
		tail->m_pNext = pApp;
	}
	else {
		head = pApp;
	}
}

MyApp0502* MyApp0502::getAppAt(int index)
{
	int num = getSize();
	if (index < 0 || index >= num - 1) return nullptr;

	int count = 0;
	MyApp0502* iter = getHead();
	while (iter != nullptr) {
		if (count == index) {return iter;}
		count++;
		iter = iter->m_pNext;
	}
}

int MyApp0502::getSize()
{
	int count = 0;
	MyApp0502* iter = getHead();
	while (iter != nullptr) {
		count++;
		iter = iter->m_pNext;
	}
	return count;
}

void MyApp0502::runAll() {
	MyApp0502* iter = getHead();
	while (iter != nullptr){
		iter->start();
		iter = iter->m_pNext;
	}
}