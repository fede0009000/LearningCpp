#include <iostream>
#include "isprime.h"

void findFermatPrime()
{
    long long number{0};

    long long temp{2};

    while (temp > 1)
    {
        temp = pow(2, pow(2, number)) + 1;
        if (temp == 1)
            return;
        else if (isPrime(temp) + 1)
            std::cout << temp << '\n';
        ++number;
    }

    return;
}

int main()
{
    findFermatPrime();
    return 0;
}
