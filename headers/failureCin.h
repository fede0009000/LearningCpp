#ifndef FAILURECIN
#define FAILURECIN

#include <limits>
#include <iostream>

bool failureCin() {
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}

#endif
