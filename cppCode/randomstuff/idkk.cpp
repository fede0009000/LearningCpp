#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::string arr{1, 2, 3, 4, 5};

    std::cout << *std::find(arr.begin(), arr.end(), 3) + 0;
}
