#ifndef NTHFIBONACCI
#define NTHFIBONACCI

long long nthFibonacci(int n) { //overflows too easily, thus long long
    if(n == 0) return 0;
    if(n == 1 || n==2) return 1;
    int temp{1};
    int temp2{1};
    for(int i{2}; i<n; ++i) {
       temp += temp2;
       temp2 = temp - temp2;
    }
    return temp;
}

#endif
