#include <iostream>

void fizzbuzz(int n) {
    for(int i{1}; i <= n; ++i) {
        if(i%3 == 0) std::cout << "fizz";
        if(i%5 == 0) std::cout << "buzz";
        if(i%3 && i%5) std::cout << i;
        std::cout << '\n';
    }
}


int main() {
    fizzbuzz(15);
    return 0;
}
