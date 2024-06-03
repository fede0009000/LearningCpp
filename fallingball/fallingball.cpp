#include <iostream>
#include <cmath>

void getHeight(double& height) {
    std::cout << "Insert the height at which the ball starts falling: ";
    std::cin >> height;
    return;
}

void calculateAndPrintHeight(double& height, const double& gravity) {
    //formula for a free falling body starting at velocity 0 is 1/2 * gravity * time * time = distance fallen
    std::cout << "The ball will hit the ground after " << sqrt((2*height)/gravity) << " seconds." << '\n';
    return;
}


int main() {
    constexpr double gravity {9.8};
    double height{};
    
    getHeight(height);

    calculateAndPrintHeight(height, gravity);
    
    return 1;
}
