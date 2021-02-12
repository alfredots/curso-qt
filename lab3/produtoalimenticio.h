#ifndef PRODUTOALIMENTICIO_H
#define PRODUTOALIMENTICIO_H
#include "iproduto.h"

class ProdutoAlimenticio: public IProduto
{
public:
    ProdutoAlimenticio();
    virtual void devolver () const;
};

#endif // PRODUTOALIMENTICIO_H
