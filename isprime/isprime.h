#ifndef ISPRIME
#define ISPRIME

bool isPrime(const long long number) {
    if(number<=1) return false;
    else if(number == 2) return true;
    else if(!(number%2)) return false;
    for(int i{3}; (i*i)<number ; ++i) {
        if((number%i) == 0) return false;
    }
    return true;
}

long long pow(const long long& num, int exponent) {
    long long temp{num};
    if(exponent == 0) return 1;
    else if(exponent < 0) return 0;
    while(exponent>1) {
        temp*=num;
        --exponent;
    }
    return temp;
}

#endif
