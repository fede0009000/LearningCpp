#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& v) {
    std::cout << "( ";

    bool first{true};
    for(const auto& i : v) {
        if(!first) std::cout << ", ";
        std::cout << i;
        first = false;
    }
    std::cout << " ):\n";
} 

template <typename T>
std::pair<std::size_t, std::size_t> vecToMinMaxPair(const std::vector<T>& v) {
    std::size_t min{0};
    std::size_t max{0};
    for(std::size_t i{0}; i < v.size(); ++i) {
        if(v[i] < v[min]) min = i;
        if(v[i] > v[max]) max = i;
    }

    return {min, max};
}

int main() {
    std::vector<int> v1;
    
    std::cout << "Enter numbers to add (use -1 to stop): ";
    int input;
    std::cin >> input;
    if(input == -1) {
        std::cout << "The array you entered is empty.";
        return 0;
    }
    v1.push_back(input);
    while(true) {
        std::cin >> input;
        if(input == -1) break;
        v1.push_back(input);
    }

    auto p1{vecToMinMaxPair(v1)};
    std::cout << "With array: ";
    printArray(v1);
    std::cout << "The min element has index " << std::get<0>(p1) << " and value " << v1[std::get<0>(p1)] << '\n';
    std::cout << "The max element has index " << std::get<1>(p1) << " and value " << v1[std::get<1>(p1)] << '\n';
}
