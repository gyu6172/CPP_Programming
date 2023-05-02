#ifndef _MYDRAWAPP0502_H__
#define _MYDRAWAPP0502_H__

#include "MyApp0502.h"
#include <string>

class MyDrawApp0502 :
    public MyApp0502
{
public:
    MyDrawApp0502(std::string name);
    void initInstance();
    void run();
    void exitInstance();
};

#endif
