#include "iproduto.h"

void IProduto::setImposto(IImposto *imposto)
{
    _imposto = imposto;
}

IProduto::IProduto(IImposto *imposto)
    : _imposto {imposto}
{
}
