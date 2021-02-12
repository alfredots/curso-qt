#include "produtoeletronico.h"


void ProdutoEletronico::devolver() const
{
    _imposto->calcular();
    cout << "devolver produto eletronico" << endl;
}
