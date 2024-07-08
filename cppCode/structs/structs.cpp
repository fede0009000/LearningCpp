#include <iostream>

// just experimenting

struct Point3d
{
    int x{0};
    int y{0};
    int z{0};
};

Point3d &getInput(Point3d &bruh)
{
    std::cout << "Inserisci x y e z:";
    int x, y, z;
    std::cin >> x >> y >> z;
    bruh = {x, y, z};
    return bruh;
}

int main()
{
    Point3d bruh{};
    Point3d damn{getInput(bruh)};
    std::cout << bruh.x << ',' << bruh.y << ',' << bruh.z << '\n';
    bruh = {2, 3, 4};
    std::cout << bruh.x << ',' << bruh.y << ',' << bruh.z << '\n';
    return 0;
}
