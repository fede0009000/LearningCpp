#ifndef DECK
#define DECK

#include <cassert>
#include <iostream>
#include <array>
#include <algorithm>
#include "Random.h"
#include "cards.hpp"

class Deck
{
private:
    std::array<Card, 52> m_deck{};
    std::size_t m_cardNum{0};

public:
    // constructor
    Deck()
    {
        std::size_t i{0};
        for (const auto &s : Card::allSuits)
        {
            for (const auto &r : Card::allRanks)
            {
                m_deck[i] = Card{r, s};
                ++i;
            }
        }
    }

    // deal card
    const Card &dealCard()
    {
        assert(m_cardNum < 52);
        return m_deck[m_cardNum++];
    }

    // shuffle
    void shuffle()
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        m_cardNum = 0;
        return;
    }
};

#endif
