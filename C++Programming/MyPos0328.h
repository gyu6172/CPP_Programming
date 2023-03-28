#ifndef __MYPOS_H__
#define __MYPOS__H_
#include <string>
class MyPos
{
	public:
	float m_x, m_y;
	MyPos(float x, float y);

	std::string getString();

	void print();
};


#endif

