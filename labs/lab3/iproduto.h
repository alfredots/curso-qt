#ifndef IPRODUTO_H
#define IPRODUTO_H

class IImposto;

class IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    virtual ~IProduto() = default;
    void setImposto(IImposto *imposto);
    virtual void devolver() = 0;

protected:
    explicit IProduto(IImposto *imposto);
    IImposto *_imposto;
};

#endif // IPRODUTO_H
