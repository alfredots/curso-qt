#include <iostream>

using namespace std;

#include "produtoalimenticio.h"
#include "produtoeletronico.h"
#include "ipi.h"
#include "icms.h"

int main()
{
    // Alocando os impostos
    IImposto *ipi = new IPI;
    IImposto *icms = new ICMS;

    // Alocando os produtos com IPI
    IProduto *produtoAlimenticio = new ProdutoAlimenticio {ipi};
    IProduto *produtoEletronico = new ProdutoEletronico {ipi};

    // Devolvendo os produtos com IPI
    produtoAlimenticio->devolver();
    produtoEletronico->devolver();

    // Mudando o imposto dos produtos para ICMS
    produtoAlimenticio->setImposto(icms);
    produtoEletronico->setImposto(icms);

    // Devolvendo os produtos com ICMS
    produtoAlimenticio->devolver();
    produtoEletronico->devolver();

    // Liberando memoria
    delete ipi;
    delete icms;
    delete produtoAlimenticio;
    delete produtoEletronico;

    return 0;
}
