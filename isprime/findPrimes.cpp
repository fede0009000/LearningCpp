#include <iostream>
#include "findPrimes.h"

int main() {
    std::cout << "Enter a number corresponding to the nth prime you're looking for (ex. 1 is 2, 2 is 3, 5 is 11, ..) or 0 to exit: " << '\n';
    int input{0};
    while(true) {
        std::cin >> input;
        if(!input) return 0;
        std::cout << "The " << input << "th prime is " << findPrimes(input) << "\n\n";

        std::cout << "Enter a number corresponding to the nth prime you're looking for or 0 to exit: " << '\n';
    }
    return 1;
}
