#include <iostream>
#include "nthFibonacci.h"

int main()
{
    std::cout << "Enter a number corresponding to the nth positive Fibonacci number you're looking for (ex. 1 is 1, 3 is 2, 6 is 8, ..) or -1 to exit: " << '\n';
    int input{0};
    while (true)
    {
        std::cin >> input;
        if (input < 0)
            return 0;
        std::cout << "The " << input << "th Fibonacci number is " << nthFibonacci(input) << "\n\n";

        std::cout << "Enter a number corresponding to the nth positive Fibonacci number you're looking for or -1 to exit: " << '\n';
    }
    return 1;
}
