#include "produtoalimenticio.h"

#include <iostream>
using namespace std;

#include <cassert>

#include "iimposto.h"

ProdutoAlimenticio::ProdutoAlimenticio(const shared_ptr<IImposto> &imposto)
    : IProduto {imposto}
{
}

ProdutoAlimenticio::~ProdutoAlimenticio()
{
    cout << "ProdutoAlimenticio destructor" << endl;
}

void ProdutoAlimenticio::devolver()
{
    assert(_imposto != nullptr);
    cout << "Devolvendo produto alimenticio com imposto = " << _imposto->calcular() << endl;
}
