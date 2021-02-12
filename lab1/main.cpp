#include <iostream>
#include <vector>

using namespace std;

struct Produto
{
    string nome;
    float preco;
};

struct Compra
{
    string cliente;
    vector<Produto> produtos;
};


void totalCompra(const Compra &compra)
{
    float sum = 0.0;
    for (const auto &produto: compra.produtos) {
        sum += produto.preco;
        cout << "produto: " << produto.nome << "/preço: " << produto.preco << endl;
    }
    cout << "Valor total da compra: " << sum << endl;
}

void cancelarCompra(Compra &compra)
{
    compra.cliente.clear();
    compra.produtos.clear();
    cout << "Compra foi cancelada" << endl;
}

auto main() -> int
{
    Compra c1 {"Marcelo",{
        {"Manga", 7.99},
        {"Cerveja", 7.99},
        {"Desodorante", 12.99}
    }};
    totalCompra(c1);
    cancelarCompra(c1);
    cout << c1.cliente << c1.produtos.size() << endl;
    cout << "Hello World!" << endl;
    return 0;
}
