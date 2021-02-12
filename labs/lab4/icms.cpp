#include "icms.h"

#include <iostream>
using namespace std;

ICMS::~ICMS()
{
    cout << "ICMS destructor" << endl;
}

float ICMS::calcular() const
{
    return 6.9;
}
