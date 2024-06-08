#ifndef FACTORIAL
#define FACTORIAL

#include <iostream>
//making it with non-type templates just to understand how they work
template <int N>
constexpr long long factorial() {
    static_assert(N>=0, "You can't calculate the factorial of a negative number!");
    if(N==0) return 1;
    else {
        long long temp{N};
        for(int i{1}; i<N; ++i) {
            temp = temp*(N-i);
        }
        return temp;
    }
}

#endif
