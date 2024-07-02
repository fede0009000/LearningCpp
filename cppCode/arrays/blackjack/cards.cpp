#include <iostream>
#include <array>

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

    constexpr int value() const {
        static constexpr std::array rankValues {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return rankValues[rank];
    }
};


int main()
{
    // Print one card
    Card card { Card::rank_5, Card::suit_heart };
    std::cout << card << '\n';

    // Print all cards
    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks)
            std::cout << Card { rank, suit } << ' ';
    std::cout << '\n';

    return 0;
}
