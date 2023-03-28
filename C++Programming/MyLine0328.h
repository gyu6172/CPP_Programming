#pragma once
#ifndef __MYLINE_H__
#define __MYLINE_H__
#include "MyPos0328.h"

class MyLine {
private:
	MyPos m_p1, m_p2;

public:
	int m_dim;
	MyLine();
	MyLine(float x1, float y1, float x2, float y2);

	void print();
};
#endif