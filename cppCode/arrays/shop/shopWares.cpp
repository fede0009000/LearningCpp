#include <iostream>
#include <array>
#include "shopWares.h"

void printShop()
{
    std::cout << "Here is our selection for today:\n";

    for (auto p : Potion::types)
        std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';

    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
}
