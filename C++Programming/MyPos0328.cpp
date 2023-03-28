#include "MyPos0328.h"
#include <iostream>

//MyPos::MyPos():MyPos(0,0)
//{
//}

MyPos::MyPos(float x, float y)
{
	m_x = x;
	m_y = y;
}

std::string MyPos::getString()
{
	std::string out;		//(x, y)
	out = "(" + std::to_string(m_x) + "," + std::to_string(m_y) + ")";
	return out;
}

void MyPos::print()
{
	std::cout<<getString()<<std::endl;
}


