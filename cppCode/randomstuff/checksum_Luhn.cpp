#include <iostream>
#include <string>

// The following code takes 1 command line argument (a number) and checks if it is a valid credit card number using Luhn's algorithm.

int get_digits(unsigned long long n)
{
    int digits{0};

    while (n > 0)
    {
        n /= 10;
        ++digits;
    }

    return digits;
}

int sum_digits(unsigned long long n)
{
    int count{0};
    while (n > 0)
    {
        count += (int)(n % 10);
        n /= 10;
    }

    return count;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./checksum <number>";
        return 1;
    }

    unsigned long long number{std::stoull(std::string{argv[1]})};

    unsigned long long temp{number};
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
            sum += (int)(temp % 10);
        }
        temp /= 10;
    }

    std::cout << "The credit card number is probably" << ((sum % 10) ? " not " : " ") << "valid.\n"; 
}
