#include <iostream>

//This file contains a series of tests I did to get the fastest possible execution of a findPrimes() function.
//I reckon the fastest way could be only checking for prime factors in each number but I'm not sure about
//how I could implement that for now.

/*bool isPrimeRef(const long long& number) {
    if(number<=1) return false;
    else if(number == 2) return true;
    else if(!(number%2)) return false;
    for(int i{3}; (i*i)<number ; ++i) {
        if((number%i) == 0) return false;
    }
    return true;
}*/

/*bool isPrimePointer(const long long* number) {
    if(*number<=1) return false;
    else if(*number == 2) return true;
    else if(!(*number%2)) return false;
    for(int i{3}; (i*i)<*number ; ++i) {
        if((*number%i) == 0) return false;
    }
    return true;
}*/

void findPrimes() {
    long long num{0};
    /*while(true) {
        if(num < 0) return;
        if(isPrime(num)) std::cout << num << '\n';
        ++num;
    }*/ //trying to make it faster
    
    /*while(true) { //quite faster it seems
        if(num < 0) return;
        if(isPrimeRef(num)) std::cout << num << '\n';
        ++num;
    }*/ //trying to make it even faster

    /*while(true) { //same as ref
        if(num < 0) return;
        if(isPrimePointer(&num)) std::cout << num << '\n';
        ++num;
    }*/

    bool primeOrNot{true}; //this is way faster than the others because it doesn't use any function
    std::cout << 2 << '\n';
    num = 3;
    while(true) { 
        if(num < 0) return; //check for overflow if num somehow reaches long long limit
        primeOrNot = true;

        if(!(num%2)) primeOrNot = false;
        else {
            for(int i{2}; (i*i) < num; ++i) {
                if(num%i == 0) {
                    primeOrNot = false;
                    break;
                }
            }
        }
        
        if(primeOrNot) std::cout << num << '\n';

        ++num;
    }

    return;
}

int main() {
    findPrimes();

    return 0;
}
