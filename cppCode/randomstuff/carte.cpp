#include <iostream>
#include <vector>
#include "../headers/Random.h"
//                  1, 2, 3, 4, 5, 6, 7, 8, 9, 10
std::vector deck = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

void resetDeck()
{
    deck = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
}

bool isDeckEmpty()
{
    for (int i{0}; i < 10; ++i)
    {
        if (deck[i] > 0)
            return false;
    }
    return true;
}

int getCard()
{
    while (true)
    {
        const int card{Random::get(0, 9)};
        if (deck[card] <= 0)
            continue;
        deck[card] -= 1;
        return card + 1;
    }
}

bool play()
{
    for (long long i{0}; i < 40; ++i)
    {
        int card = getCard();
        switch (i % 3)
        {
        case 1: // 1
            if (card == 1)
                return false;
            break;
        case 2: // 2
            if (card == 2)
                return false;
            break;
        case 0: // 3
            if (card == 0)
                return false;
            break;
        };
    }
    return true;
}

int main()
{
    long long j{};
    int k{};
    std::cout << "Quante volte vuoi eseguirlo?\n";
    std::cin >> j;
    std::cout << "Quante volte vuoi ripeterlo?\n";
    std::cin >> k;

    for (int n{0}; n < k; ++n)
    {
        long long won{0};
        for (long i{0}; i < j; ++i)
        {
            if (play())
                ++won;

            resetDeck();
        }
        std::cout << j << ": " << won << " won, " << j - won << " lost.\n";
    }
}