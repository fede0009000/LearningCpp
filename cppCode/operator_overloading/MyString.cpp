#include <cassert>
#include <iostream>
#include <string>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(std::string_view str = {}) : m_string{str}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const MyString &str);

/*    MyString operator()(int start, int end) const
    {
        assert(start >= 0 && "MyString::operator(int, int): Substring is out of range");
        assert(start + end <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range.");
        return MyString{m_string.substr(static_cast<std::size_t>(start), static_cast<std::size_t>(end))};
    }*/

    std::string_view operator() (int start, int end) const
    {
        assert(start >= 0 && "MyString::operator(int, int): Substring is out of range");
        assert(start + end <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range.");

        return std::string_view{m_string}.substr(static_cast<std::size_t>(start), static_cast<std::size_t>(end));
    }
};

std::ostream &operator<<(std::ostream &out, const MyString &str)
{
    out << str.m_string;

    return out;
}

int main()
{
    MyString s{"Hello, world!"};
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
