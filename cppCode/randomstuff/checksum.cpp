#include <iostream>
#include <string>

int get_digits(long n)
{
    int digits{0};

    while (n > 0)
    {
        n /= 10;
        ++digits;
    }

    return digits;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./checksum <number>";
        return 1;
    }

    int number{std::stoi(std::string{argv[1]})};

    long temp{number};
    int digits{get_digits(number)};
    int sum{0};

    for (int i = 0; i <= digits; ++i) // i indicates the number of digits that's been removed
    {
        if ((i % 2) == 1)
        {
            sum += sum_digits((temp % 10) * 2);
        }
        else
        {
            sum += temp % 10;
        }
        temp /= 10;
    }

    return sum;
}
