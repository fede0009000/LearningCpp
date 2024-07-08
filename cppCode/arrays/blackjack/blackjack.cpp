#include <iostream>

#include "cards.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "failureCin.h"

bool failureCin();

enum gameResult
{
    dealerWin,
    playerWin,
    tie
};

namespace Settings
{
    int maxScore{21};
    int stopDrawDealerScore{17};
}

bool dealerTurn(Deck &deck, Player &dealer)
{
    Card card{};
    while (dealer.getScore() < 17)
    {
        card = deck.dealCard();
        dealer.addScore(card.value());

        std::cout << "The dealer flips a " << card << ". ";
        std::cout << "They now have: " << dealer.getScore() << '\n';

        if (dealer.getScore() > 21)
        {
            if (dealer.getAceCount() > 0)
            {
                dealer.convertAce();
            }
            else
            {
                std::cout << "The dealer went bust!" << '\n';
                return false;
            }
        }
    }
    return false;
}

bool playerTurn(Deck &deck, Player &player)
{
    Card card{};
    char input{};

    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        // get the input
        while (true)
        {
            std::cin >> input;
            if (failureCin() || (input != 'h' && input != 's'))
                continue;
            else
                break;
        }

        // check the input
        if (input == 's')
            return true;
        else
        {
            card = deck.dealCard();
            player.addScore(card.value());

            std::cout << "You were dealt: " << card << ". ";
            std::cout << "You now have: " << player.getScore() << '\n';

            if (player.getScore() > 21)
            {
                if (player.getAceCount() > 0)
                {
                    player.convertAce();
                }
                else
                {
                    std::cout << "You went bust!" << '\n';
                    return false;
                }
            }
        }
    }
}

gameResult playBlackjack()
{
    Deck deck{};
    deck.shuffle();

    Card card{};

    Player player{};
    Player dealer{};

    // first dealer card
    card = deck.dealCard();
    if (card.isAce())
        dealer.addAce();
    dealer.addScore(card.value());

    // two player cards
    for (int i{0}; i < 2; ++i)
    {
        card = deck.dealCard();
        if (card.isAce())
            player.addAce();
        player.addScore(card.value());

        if (player.getScore() > 21 && player.getAceCount() > 0)
            player.convertAce();
    }

    std::cout << "The dealer is showing: " << dealer.getScore() << '\n';
    std::cout << "You have score: " << player.getScore() << '\n';

    // player's turn
    if (!playerTurn(deck, player))
        return dealerWin; // player lost

    // dealer's turn
    if (dealerTurn(deck, dealer))
        return playerWin; // dealer lost

    if (player.getScore() == dealer.getScore())
        return tie;

    return (player.getScore() > dealer.getScore() ? playerWin : dealerWin);
}

int main()
{

    gameResult result{playBlackjack()};

    if (result == tie)
        std::cout << "It's a tie.\n";
    else
        std::cout << (result == playerWin ? "You win!\n" : "You lose!\n");
}
