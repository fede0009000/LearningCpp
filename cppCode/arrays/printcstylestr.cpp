#include <iostream>
#include <cstring>

void printStr(const char str[]) {
    while(*str != '\0') {
        std::cout << *str;
        ++str;
    }
    std::cout << '\n';
}

void printReverseStr(const char str[]) {
    const char* ptr{str};
    
    while(*ptr != '\0') ++ptr;
    
    while(ptr-- != str) std::cout << *ptr;
}

int main() {
    const char str[] {"Hello, world!"};
    printStr(str);
    printReverseStr(str);
}
