#include <iostream>

using namespace std;

struct Produto
{
    string nome;
    float preco;
};

void f1 (Produto *produtos)
{

    produtos[1] = {"Desodorante", 11.99};
}

auto main() -> int
{
    auto *produtos = new Produto[10];
    //isso não é uma inicialização e sim uma atribuição
    produtos[0] = {"Cerveja", 12.99};
    f1(produtos);

    cout << produtos[1].nome << " - " << produtos[1].preco << endl;

    delete[] produtos;

    return 0;
}
