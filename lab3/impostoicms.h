#include "iimposto.h"
#ifndef IMPOSTOICMS_H
#define IMPOSTOICMS_H


class ImpostoICMS: public IImposto
{
public:
    virtual ~ImpostoICMS() = default;
    float calcular();
};

#endif // IMPOSTOICMS_H
