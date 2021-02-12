#ifndef IIMPOSTO_H
#define IIMPOSTO_H
#include <iostream>
using namespace std;

class IImposto
{
public:
    virtual float calcular () = 0;
};

#endif // IIMPOSTO_H
