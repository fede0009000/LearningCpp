#include <iostream>
#include <vector>

void findPrimes()
{
    std::cout << 2 << '\n'
              << 3 << '\n';

    std::vector<long long> primes{3};
    long long n{3};
    bool isPrime{false};

    while (true)
    {
        isPrime = true;
        if (!(n % 2))
            isPrime = false;
        else
        {
            for (int i{0}; primes[i] * primes[i] <= n; ++i)
            {
                if (!(n % primes[i]))
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
        {
            std::cout << n << '\n';
            primes.insert(primes.end(), n);
        }
        ++n;
    }
}

int main()
{
    findPrimes();
    return 1;
}
