#include "produtoalimenticio.h"

#include <iostream>
using namespace std;

#include <cassert>

#include "iimposto.h"

ProdutoAlimenticio::ProdutoAlimenticio(IImposto *imposto)
    : IProduto {imposto}
{
}

void ProdutoAlimenticio::devolver()
{
    assert(_imposto != nullptr);
    cout << "Devolvendo produto alimenticio com imposto = " << _imposto->calcular() << endl;
}
