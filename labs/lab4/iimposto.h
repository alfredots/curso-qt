#ifndef IIMPOSTO_H
#define IIMPOSTO_H

class IImposto  // clazy:exclude=copyable-polymorphic
{
public:
    virtual float calcular() const = 0;
    virtual ~IImposto() = default;

protected:
    IImposto() = default;
};

#endif // IIMPOSTO_H
