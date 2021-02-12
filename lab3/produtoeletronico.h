#include "iproduto.h"
#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H


class ProdutoEletronico: public IProduto
{
public:
    ProdutoEletronico() = default;
    virtual ~ProdutoEletronico() = default;
    void devolver () const;
};

#endif // PRODUTOELETRONICO_H
