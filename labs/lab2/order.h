#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Product
{
    string name;
    float price;
};

class Order
{
public:
    Order(unsigned clientId = 0, const vector<Product> &items = {});
    Order(const Order &order);
    Order(Order &&order) noexcept;
    Order &operator=(const Order &order) noexcept;
    Order &operator=(Order &&order) noexcept;
    ~Order();

    friend ostream &operator<<(ostream &os, const Order &order);

private:
    unsigned _clientId;
    vector<Product> _items;
};

#endif // ORDER_H
