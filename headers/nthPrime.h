#ifndef FINDPRIMES
#define FINDPRIMES

long long nthPrime(int n) { //nth indicates that the function finds the nth prime
    if(n < 1) return 1;
    else if(n == 1) return 2;
    long long num{3};
    bool isPrime{true};
    for(int i{1}; i < n; ) {

        if(num < 0) return 1; //check for overflow if num somehow reaches long long limit

        isPrime = true;

        if(!(num%2)) {isPrime = false;}
        else {
            for(int j{3}; (j*j) <= num; ++j) { //loop to find divisors, j*j<num is the same as j<sqrt(num)
                if(num%j == 0) {
                    isPrime = false;//if num is divisible by j, it's obviously not prime
                    break;
                }
            }
        }
        
        if(isPrime) ++i;
            


        ++num;
    }
    return num-1;
}

#endif
