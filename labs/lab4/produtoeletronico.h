#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H

#include "iproduto.h"

class ProdutoEletronico : public IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    ProdutoEletronico(const shared_ptr<IImposto> &imposto = {});
    virtual ~ProdutoEletronico();
    virtual void devolver() override;
};

#endif // PRODUTOELETRONICO_H
