#include <array>
#include <iostream>
#include <algorithm>

int main()
{
    std::array nums{1, 2, 3, 4, 5, 6, 7};

    auto found{std::find(nums.begin(), nums.end(), 5)};
    if (found == nums.end())
        std::cout << "Valore non trovato.";
    else
        std::cout << "Valore trovato all’indice " << *found;
}
