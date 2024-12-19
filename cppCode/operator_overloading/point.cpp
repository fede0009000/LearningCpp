#include <iostream>

class Point
{
private:
    double m_x{0};
    double m_y{0};
    double m_z{0};

public:
    Point(double x, double y, double z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    Point operator+() const;

};

Point Point::operator+() const
{
    return *this;
}
