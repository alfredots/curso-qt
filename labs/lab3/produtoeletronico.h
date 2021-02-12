#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H

#include "iproduto.h"

class ProdutoEletronico : public IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    ProdutoEletronico(IImposto *imposto = nullptr);
    virtual ~ProdutoEletronico() = default;
    virtual void devolver() override;
};

#endif // PRODUTOELETRONICO_H
