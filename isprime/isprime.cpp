#include <iostream>
#include "isprime.h"

void getNumber(long long* number) {
    std::cout << '\n' << "Insert any positive integer or -1 to terminate the program: ";
    std::cin >> *number;
}

void isPrimeOutput(long long number) {
    bool prime{false};
    while(number>=0) {
            prime = isPrime(number);
            std::cout << number << ' ' << (prime ? "is" : "isn't") << " a prime number." << '\n';
            getNumber(&number);
       }
}

int main() {
    long long number{1};
    getNumber(&number);
    
    std::cout << number << (isPrime(number) ? " è " : " non è ") << "un numero primo." << "\n\n";

    return 0;
}
