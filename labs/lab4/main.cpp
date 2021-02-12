#include <iostream>
#include <memory>

using namespace std;

#include "produtoalimenticio.h"
#include "produtoeletronico.h"
#include "ipi.h"
#include "icms.h"

int main()
{
    // Alocando os impostos
    shared_ptr<IImposto> ipi {make_shared<IPI>()};
    shared_ptr<IImposto> icms {make_shared<ICMS>()};
    cout << "#ipi references: " << ipi.use_count() << endl;
    cout << "#icms references: " << icms.use_count() << endl;

    // Alocando os produtos com IPI
    unique_ptr<IProduto> produtoAlimenticio {make_unique<ProdutoAlimenticio>(ipi)};
    unique_ptr<IProduto> produtoEletronico {make_unique<ProdutoEletronico>(ipi)};

    // Devolvendo os produtos com IPI
    produtoAlimenticio->devolver();
    produtoEletronico->devolver();

    // Mudando o imposto dos produtos para ICMS
    produtoAlimenticio->setImposto(icms);
    produtoEletronico->setImposto(icms);

    // Devolvendo os produtos com ICMS
    produtoAlimenticio->devolver();
    produtoEletronico->devolver();

    // Nao eh necessario deletes explicitos aqui!

    return 0;
}
