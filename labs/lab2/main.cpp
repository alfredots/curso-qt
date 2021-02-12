#include <iostream>

#include "order.h"

using namespace std;

// NOLINTNEXTLINE(performance-unnecessary-value-param)
void function1(Order order)  // clazy:exclude=function-args-by-ref
{
    (void)order;  // Silent unused parameter warning
}

void function2(const Order &order)
{
    (void)order;  // Silent unused parameter warning
}

void function3(Order &&order)
{
    (void)order;  // Silent unused parameter warning
}

Order function4()
{
    return {
        20U,
        {
            { "Barbecue", 20.5 },
            { "Water", 1.75 }
        }
    };
}

int main()
{
    Order order1 {
        10U,
        {
            { "Beer", 10.5 },
            { "Cheese", 15.75 }
        }
    };  // Constructor invoked
    cout << "Order1: " << order1;

    // NOLINTNEXTLINE(performance-unnecessary-copy-initialization)
    auto order2 {order1};  // Copy constructor invoked
    cout << "Order2: " << order2;

    // NOLINTNEXTLINE(readability-isolate-declaration)
    Order order3, order4;  // Constructor invoked twice
    order4 = order3 = order2;  // Copy assignment invoked twice
    cout << "Order3: " << order3;
    cout << "Order4: " << order4;

    function1(order1);  // Copy constructor invoked

    cout << "Receiving by value and initializing" << endl;
    auto order5 = function4();  // Constructor (local object) and move constructor invoked

    cout << "Receiving by value and assigning" << endl;
    Order order6;
    order6 = function4();  // Constructor (local object) and move assignment invoked
    cout << "Order6: " << order6;

    return 0;
    // All destructor invoked at program termination
}
