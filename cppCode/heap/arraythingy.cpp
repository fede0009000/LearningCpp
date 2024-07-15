#include <iostream>
#include <string>
#include <algorithm>
#include "failureCin.h"

int main()
{
    std::cout << "How many names would you like to enter? ";

    int size{};
    do
    {
        std::cin >> size;
    } while (failureCin());

    std::string *names{new std::string[size]{}};

    for (int i{0}; i < size; ++i)
    {
        std::cout << "Enter name #" << i << ": ";
        do
        {
            std::getline(std::cin >> std::ws, names[i]);
        } while (failureCin());
    }

    std::sort(names, names + size);

    std::cout << "Here is your sorted list:\n";
    for (int i{0}; i < size; ++i)
    {
        std::cout << names[i] << '\n';
    }

    delete[] names;
}
