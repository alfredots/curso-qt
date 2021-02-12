#include "ipi.h"

#include <iostream>
using namespace std;

IPI::~IPI()
{
    cout << "IPI destructor" << endl;
}

float IPI::calcular() const
{
    return 2.8;
}
