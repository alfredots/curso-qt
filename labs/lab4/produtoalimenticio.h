#ifndef PRODUTOALIMENTICIO_H
#define PRODUTOALIMENTICIO_H

#include "iproduto.h"

class ProdutoAlimenticio : public IProduto  // clazy:exclude=copyable-polymorphic
{
public:
    ProdutoAlimenticio(const shared_ptr<IImposto> &imposto = {});
    virtual ~ProdutoAlimenticio();
    virtual void devolver() override;
};

#endif // PRODUTOALIMENTICIO_H
