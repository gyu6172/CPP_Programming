#ifndef _MYAPP0502_H__
#define _MYAPP0502_H__

#include <string>

class MyApp0502
{
private:
	MyApp0502* m_pNext;
	static MyApp0502* head;

public:
	std::string m_name;
	MyApp0502(std::string name);
	virtual void start();
	virtual void initInstance() = 0;	//순수 가상 함수(pure virtual function)
	virtual void run() = 0;
	virtual void exitInstance() = 0;

	static MyApp0502* getHead();
	static void addApp(MyApp0502* pApp);
	static MyApp0502* getTail();
	static MyApp0502* getAppAt(int index);
	static int getSize();
	static void runAll();
};
#endif

