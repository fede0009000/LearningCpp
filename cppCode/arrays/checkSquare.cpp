#include <iostream>
#include "failureCin.h"

constexpr int squares[]{0, 1, 4, 9};

bool foundSquare(int input)
{
    for (int i : squares)
    {
        if (i == input)
            return true;
    }
    return false;
}

int main()
{
    int input{};
    while (true)
    {
        std::cout << "Enter a number or -1 to quit: ";
        std::cin >> input;

        if (failureCin())
            continue;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input == -1)
            return 0;
        else
        {
            std::cout << input << (foundSquare(input) ? " is " : " isn't ") << "a perfect square between 0 and 9.\n";
        }
    }
    return 1;
}
