#ifndef __MY_PLACE_H__
#define __MY_PLACE_H__

#include <string>
using namespace std;

class MyPlace
{
private:
	string name;
	float distance;
public:
	MyPlace(string name, float distance);
	void print();
};
#endif

