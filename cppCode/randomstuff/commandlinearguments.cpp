#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    for (int i{0}; i < argc; ++i)
    {
        std::cout << i << " " << argv[i] << '\n';
    }
}
