#ifndef ICMS_H
#define ICMS_H

#include "iimposto.h"

class ICMS : public IImposto  // clazy:exclude=copyable-polymorphic
{
public:
    ICMS() = default;
    virtual ~ICMS() = default;
    virtual float calcular() const override;
};

#endif // ICMS_H
