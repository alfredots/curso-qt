#include "order.h"

#include <iostream>

Order::Order(unsigned clientId, const vector<Product> &items)
    : _clientId {clientId}, _items {items}
{
    cout << "Constructor" << endl;
}

Order::Order(const Order &order)
    : _clientId {order._clientId}, _items {order._items}
{
    cout << "Copy constructor" << endl;
}

Order::Order(Order &&order) noexcept
    : _clientId {order._clientId}, _items {std::move(order._items)}
{
    order._clientId = 0;
    order._items = {};
    cout << "Move constructor" << endl;
}

Order &Order::operator=(const Order &order) noexcept
{
    _clientId = order._clientId;
    _items = order._items;
    cout << "Copy assignment" << endl;

    return *this;
}

Order &Order::operator=(Order &&order) noexcept
{
    _clientId = order._clientId;
    _items = std::move(order._items);
    order._clientId = 0;
    order._items = {};
    cout << "Move assignment" << endl;

    return *this;
}

Order::~Order()
{
    cout << "Destructor" << endl;
}

ostream &operator<<(ostream &os, const Order &order)
{
    os << "Order[" << order._clientId << ", { ";
    for (const auto &product : order._items) {
        os << "[" << product.name << ", " << product.price << "] ";
    }
    os << "}" << "]" << endl;
    return os;
}
