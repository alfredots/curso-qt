#ifndef PRODUTOALIMENTICIO_H
#define PRODUTOALIMENTICIO_H

#include "iproduto.h"

class ProdutoAlimenticio : public IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    ProdutoAlimenticio(IImposto *imposto = nullptr);
    virtual ~ProdutoAlimenticio() = default;
    virtual void devolver() override;
};

#endif // PRODUTOALIMENTICIO_H
