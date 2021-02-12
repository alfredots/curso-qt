#ifndef IPRODUTO_H
#define IPRODUTO_H
#include "iimposto.h"
#include <iostream>
#include <memory>
using namespace std;
class IImposto;


class IProduto
{
public:
    virtual void devolver () const = 0;
    void setImposto(const shared_ptr<IImposto> imposto) {
        _imposto = imposto;
    }
protected:
    shared_ptr<IImposto> _imposto;
};

#endif // IPRODUTO_H
