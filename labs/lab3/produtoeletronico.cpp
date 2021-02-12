#include "produtoeletronico.h"

#include <iostream>
using namespace std;

#include <cassert>

#include "iimposto.h"

ProdutoEletronico::ProdutoEletronico(IImposto *imposto)
    : IProduto {imposto}
{
}

void ProdutoEletronico::devolver()
{
    assert(_imposto != nullptr);
    cout << "Devolvendo produto eletronico com imposto = " << _imposto->calcular() << endl;
}
