#include <iostream>

using namespace std;

void function1(int x)
{
    x++;
}

void function2(int *x)
{
    (*x)++;
}

void function3(int &x)
{
    x++;
}

void function4(const int &x)  // clazy:exclude=function-args-by-value
{
    // x++;  // Error: we cannot change the value of constant references
    cout << "In function4: x = " << x << endl;
}

int main()
{
    int x = 10;
    cout << "At beginning: x = " << x << endl;
    function1(x);
    cout << "After function1: x = " << x << endl;
    function2(&x);
    cout << "After function2: x = " << x << endl;
    function3(x);
    cout << "After function3: x = " << x << endl;
    function4(x);

    return 0;
}
