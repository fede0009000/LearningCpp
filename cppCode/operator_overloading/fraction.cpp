#include <iostream>
#include <numeric>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};
public:
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
        {
            reduce();
        }
    
    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    friend Fraction operator*(const Fraction& fr1, int a);
    friend Fraction operator*(int a, const Fraction& fr1);
    friend Fraction operator*(const Fraction& fr1, const Fraction& fr2);

    friend bool operator==(const Fraction& fr1, const Fraction& fr2);
    friend bool operator!=(const Fraction& fr1, const Fraction& fr2);
    friend bool operator>(const Fraction& fr1, const Fraction& fr2);
    friend bool operator>=(const Fraction& fr1, const Fraction& fr2);
    friend bool operator<(const Fraction& fr1, const Fraction& fr2);
    friend bool operator<=(const Fraction& fr1, const Fraction& fr2);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fr1);
    friend std::istream& operator>>(std::istream& in, Fraction& fr1);

    void reduce()
    {
        int gcd{std::gcd(m_numerator, m_denominator)};
        if (gcd)
        {
            m_numerator = m_numerator / gcd;
            m_denominator = m_denominator / gcd;
        }
    }
};

Fraction operator*(const Fraction& fr1, int a)
{
    return Fraction{fr1.m_numerator * a, fr1.m_denominator};
}

Fraction operator*(int a, const Fraction& fr1)
{
    return Fraction{fr1.m_numerator * a, fr1.m_denominator};
}

Fraction operator*(const Fraction& fr1, const Fraction& fr2)
{
    return Fraction{fr1.m_numerator * fr2.m_numerator, fr1.m_denominator * fr2.m_denominator};
}

bool operator==(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator == fr2.m_numerator) && (fr1.m_denominator == fr2.m_denominator);
}

bool operator!=(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator != fr2.m_numerator) && (fr1.m_denominator != fr2.m_denominator);
}

bool operator>(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator > fr2.m_numerator) && (fr1.m_denominator > fr2.m_denominator);
}

bool operator>=(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator >= fr2.m_numerator) && (fr1.m_denominator >= fr2.m_denominator);
}

bool operator<(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator < fr2.m_numerator) && (fr1.m_denominator < fr2.m_denominator);
}

bool operator<=(const Fraction& fr1, const Fraction& fr2)
{
    return (fr1.m_numerator <= fr2.m_numerator) && (fr1.m_denominator <= fr2.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& fr1)
{
    out << fr1.m_numerator << '/' << fr1.m_denominator;

    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fr1)
{
    int n{};
    char ignore{};
    int d{1};
    in >> n >> ignore >> d;

    if(in)
        fr1 = Fraction{n, d};

    return in;
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}
