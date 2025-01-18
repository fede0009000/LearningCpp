#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char &operator[](std::string_view index)
    {
        auto found{std::find_if(m_map.begin(), m_map.end(),
                                [index](const auto &student)
                                { return index == student.name; })};

        if (found != m_map.end())
            return found->grade;
        else
            return m_map.emplace_back(StudentGrade{std::string{index}}).grade;
    }
};

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}
