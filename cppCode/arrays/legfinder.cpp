#include <cassert>
#include <iostream>
#include <vector>

namespace Animals
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    const std::vector<int> legs{2, 4, 4, 4, 2, 0};
}

int main()
{
    assert(std::size(Animals::legs) == Animals::max_animals);

    std::cout << Animals::legs[Animals::elephant];
}
