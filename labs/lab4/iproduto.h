#ifndef IPRODUTO_H
#define IPRODUTO_H

#include <memory>
using namespace std;

class IImposto;

class IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    virtual ~IProduto() = default;
    void setImposto(const shared_ptr<IImposto> &imposto);
    virtual void devolver() = 0;

protected:
    explicit IProduto(const shared_ptr<IImposto> &imposto = {});
    shared_ptr<IImposto> _imposto;
};

#endif // IPRODUTO_H
