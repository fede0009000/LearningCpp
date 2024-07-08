#include "deck.hpp"
#include <iostream>

class Player
{
private:
    int m_score{0};
    int m_aceCount{0};

public:
    Player() = default;
    Player(int score)
        : m_score{score}
    {
    }

    int getScore() const { return m_score; }
    int getAceCount() const { return m_aceCount; }

    void addScore(int score) { m_score += score; }
    void addAce() { ++m_aceCount; }

    void convertAce()
    {
        --m_aceCount;
        m_score -= 10;
    }
};
