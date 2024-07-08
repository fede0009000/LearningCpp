#include <iostream>
#include <vector>
#include <string_view>

template <typename T>
bool isInVector(const T &string, const std::vector<std::string_view> &vector)
{
    for (const auto &temp : vector)
        if (string == temp)
            return true;

    return false;
}

int main()
{
    std::vector<std::string_view> list{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::string input{};
    std::cout << "Enter a name: ";
    std::cin >> input;

    std::cout << '"' << input << '"' << (isInVector(input, list) ? " was" : " wasn't") << " found" << '\n';
}
