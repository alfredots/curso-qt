#include "iimposto.h"
#ifndef IMPOSTOIPI_H
#define IMPOSTOIPI_H


class ImpostoIPI: public IImposto
{
public:
    ImpostoIPI();
    float calcular() const;
};

#endif // IMPOSTOIPI_H
