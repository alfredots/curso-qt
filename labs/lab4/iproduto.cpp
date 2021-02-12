#include "iproduto.h"

#include <iostream>
using namespace std;

void IProduto::setImposto(const shared_ptr<IImposto> &imposto)
{
    _imposto = imposto;
}

IProduto::IProduto(const shared_ptr<IImposto> &imposto)
    : _imposto {imposto}
{
    cout << "#imposto references: " << imposto.use_count() << endl;
}
