#include <cassert>
#include <iostream>
#include <array>
#include <algorithm>
#include "Random.h"

struct Card {
    enum Rank {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,
    
        max_suits   
    };
    static constexpr std::array allRanks {rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
    static constexpr std::array allSuits {suit_club, suit_diamond, suit_heart, suit_spade};

    Rank rank{};
    Suit suit{};


    
    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        static constexpr std::array ranks {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        static constexpr std::array suits {'C', 'D', 'H', 'S'};

        out << ranks[card.rank] << suits[card.suit];

        return out;
    }

    static constexpr std::array rankValues {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    constexpr int value() const {
        return rankValues[rank];
    }
};

class Deck {
private:
    std::array<Card, 52> m_deck {};
    std::size_t m_cardNum {0};
public:
//constructor
    Deck() {
        std::size_t i{0};
        for(const auto& s : Card::allSuits) {
            for(const auto& r : Card::allRanks) {
                m_deck[i] = Card {r, s};
                ++i;
            }
        }
    }

//deal card
    const Card& dealCard() {
        assert(m_cardNum < 52);
        return m_deck[m_cardNum++];
    } 

//shuffle
    void shuffle() {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        m_cardNum = 0;
        return;
    }
};

int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}
