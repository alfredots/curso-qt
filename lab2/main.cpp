#include <iostream>
#include <vector>

using namespace std;

struct Produto {
    string nome;
    float preco;
};

class Compra
{
public:
    Compra(string cliente = {}, const vector<Produto> &produtos = {}): _cliente(cliente), _produtos(produtos) {
        cout << "Executando o construtor" << endl;
    }
    Compra(const Compra &other): _cliente(other._cliente), _produtos(other._produtos) {
        cout << "Executando o copy constructor" << endl;
    }
    Compra(Compra &&other): _cliente(other._cliente), _produtos(other._produtos)
    {
        other._cliente.clear();
        other._produtos.clear();
        cout << "Executando move constructor" << endl;
    }
    auto operator=(const Compra & other) -> Compra & {
        _cliente = other._cliente;
        _produtos = other._produtos;
        cout << "Executando o operator=" << endl;
        return *this;
    }
    auto operator+(const Compra &other) const -> Compra {
        Compra resultado {*this};
        resultado._cliente.append(" e " + other._cliente);
        resultado._produtos.reserve(_produtos.size() + other._produtos.size());
        resultado._produtos.insert(resultado._produtos.end(), other._produtos.begin(), other._produtos.end());
        cout << "Executando o operator+" << endl;
        return resultado;
    }
    Compra &operator<<(const Produto &produto) {
        _produtos.push_back(produto);
        cout << "Executando o operator <<" << endl;
        return *this;
    }
    auto produtos() const -> vector<Produto> {
        return _produtos;
    }
    auto cliente() const -> string {
        return _cliente;
    }
private:
    string _cliente;
    vector<Produto> _produtos;
};

auto itemMaisCaro(const Compra &compra) -> Produto
{
    Produto produtoMaisCaro {"",0};
    for (auto &produto: compra.produtos()) {
        if(produto.preco > produtoMaisCaro.preco) {
            produtoMaisCaro = produto;
        }
    }
    return produtoMaisCaro;
}



auto main() -> int
{
    Compra c1;
    Compra c2  {
        "Joao",
        {
            {"Cerveja", 12.99},
            {"Desodorante", 10.99}
        }
    };
    Compra c3 {"Jose", {{"Melancia", 2.99}} };
    Compra c4 = c2+c3; //c2.operator+(c3)
    c4 = c2+c3;
    cout << c4.cliente() << endl;
    cout << "----" << endl;
    Produto maisCaro = itemMaisCaro(c2);
    Compra c5 {c4};
    cout << c5.produtos().size() << endl;
    c5 << maisCaro << maisCaro; //c5.operator<<(c5)
    cout << c5.produtos().size() << endl;
    return 0;
}
