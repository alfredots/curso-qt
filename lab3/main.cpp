#include <iostream>
#include <memory>
using namespace std;

#include "produtoeletronico.h"
#include "impostoicms.h"

int main()
{
    unique_ptr<IProduto> p1 { make_unique<ProdutoEletronico>() };
    shared_ptr<ImpostoICMS> imposto { make_unique<ImpostoICMS>() };
    p1->setImposto(imposto);
    p1->devolver();
    return 0;

}
