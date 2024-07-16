#include <iostream>
#include <functional>
#include "failureCin.h"

// type aliases
using ArithmeticFunction = std::function<int(int, int)>;

// forward declarations
int inputInt();
char inputChar();
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
ArithmeticFunction getArithmeticFunction(char c);

// main
int main()
{
    int a{inputInt()};
    char op{inputChar()};
    int b{inputInt()};

    ArithmeticFunction func{getArithmeticFunction(op)};
    if (func)
        std::cout << a << ' ' << op << ' ' << b << " = " << func(a, b);
}

// functions

int inputInt()
{
    int x{0};
    while (true)
    {
        std::cout << "Enter an integer: ";
        std::cin >> x;
        if (failureCin())
            continue;
        else
            return x;
    }
}

char inputChar()
{
    char x{0};
    while (true)
    {
        std::cout << "Choose an operation (+, -, *, /) ";
        std::cin >> x;
        if (failureCin())
            continue;
        else
            return x;
    }
}

int add(int x, int y) { return x + y; }

int subtract(int x, int y) { return x - y; }

int multiply(int x, int y) { return x * y; }

int divide(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "NaN\n";
        std::exit(1);
    }
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char c)
{
    switch (c)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return divide;
    }

    return nullptr;
}
