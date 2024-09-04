#include <iostream>
#include <string>

void print_stuff(int num_chars, std::string prefix = "")
{
    prefix.reserve(9);
    if (num_chars <= 0)
    {
        return;
    }
    else if(num_chars == 8)
    {
        std::cout << "New character just dropped\n";
    }
    for (int i = 33; i < 127; ++i)
    {
        prefix.append(1, static_cast<char>(i));
        print_stuff(num_chars - 1, prefix);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        std::cerr << "Usage: ./crackpwd <min_characters> <max_characters>";
        return 1;
    }

    int min{std::stoi(std::string{argv[1]})};
    int max{std::stoi(std::string{argv[2]})};

    for (int i = min; i <= max; ++i)
    {
        print_stuff(i);
    }

    std::cout << "\nDone\n";

    return 0;
}
