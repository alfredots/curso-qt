#ifndef IPI_H
#define IPI_H

#include "iimposto.h"

class IPI : public IImposto  // clazy:exclude=copyable-polymorphic
{
public:
    IPI() = default;
    virtual ~IPI();
    virtual float calcular() const override;
};

#endif // IPI_H
