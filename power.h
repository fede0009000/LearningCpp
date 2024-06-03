#ifndef POWERS
#define POWERS

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
