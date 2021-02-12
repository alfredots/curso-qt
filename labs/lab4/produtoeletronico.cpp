#include "produtoeletronico.h"

#include <iostream>
using namespace std;

#include <cassert>

#include "iimposto.h"

ProdutoEletronico::ProdutoEletronico(const shared_ptr<IImposto> &imposto)
    : IProduto {imposto}
{
}

ProdutoEletronico::~ProdutoEletronico()
{
    cout << "ProdutoEletronico destructor" << endl;
}

void ProdutoEletronico::devolver()
{
    assert(_imposto != nullptr);
    cout << "Devolvendo produto eletronico com imposto = " << _imposto->calcular() << endl;
}
