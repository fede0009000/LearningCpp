#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Random.h"
#include "failureCin.h"

int getNumber();
int nextSquare(int curSquare);
int closestGuess(const std::vector<int>& v, int guess);


int main()
{
    std::cout << "Start where? ";
    const int startingNumber{getNumber()};

    std::cout << "How many? ";
    const int numberOfSquares{getNumber()};

    const int multiplier{Random::get(2, 4)};

    std::vector<int> solutions{};
    int tmp{startingNumber};
    for (int i{0}; i < numberOfSquares; ++i)
    {
        tmp = nextSquare(tmp);
        solutions.push_back(tmp * multiplier);
    }

    std::cout << "I generated " << numberOfSquares << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";

    int guess{};
    for (int solutionsLeft{numberOfSquares}; solutionsLeft > 0; --solutionsLeft)
    {   
        guess = getNumber();
        auto found{std::find(solutions.begin(), solutions.end(), guess)};
        if (found == solutions.end())
        {
            
            std::cout << guess << " is wrong! " << "Try " << closestGuess(solutions, guess) << " next time.\n";
            return 0;
        }

        std::cout << "Nice! " << solutionsLeft << " numbers left.\n";
        solutions.erase(found);
    }

    std::cout << "Nice! You found all numbers, good job!";
}

int getNumber()
{
    int n;
    do
    {
        std::cin >> n;
    } while (failureCin());

    return n;
}

int nextSquare(int curSquare)
{
    for (int i = 1; i * i <= curSquare; ++i)
    {
        if (curSquare / i  == i)
        {
            return (i + 1) * (i + 1);
        }
    }

    return 0;
}

int closestGuess(const std::vector<int>& v, int guess)
{
    int closest{v[0]};
    for (int i : v)
    {
        if (std::abs(guess - i) < std::abs(closest - i))
            closest = i;
    }

    return closest;
}
