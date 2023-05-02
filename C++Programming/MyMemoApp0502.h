#ifndef _MYMEMOAPP0502_H__
#define _MYMEMOAPP0502_H__

#include "MyApp0502.h"
#include <string>

class MyMemoApp0502 :
    public MyApp0502
{
public:
    MyMemoApp0502(std::string name);
    void initInstance();
    void run();
    void exitInstance();
};
#endif

