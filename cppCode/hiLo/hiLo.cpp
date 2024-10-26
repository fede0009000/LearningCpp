#include <iostream>
#include "Random.h"
#include <limits>
#include "failureCin.h"

namespace Settings
{
    int max_num{100};   // I'm thinking of a number between 1 and max_num
    int max_guesses{7}; // Maximum number of guesses before the player loses
}

void hiLo()
{
    // Settings::max_num is 100 by default.
    const int num{Random::get(1, Settings::max_num)};

    // Description
    std::cout << "Let's play a game. I'm thinking of a number between 1 and "
              << Settings::max_num // Settings::max_num is 100 by default
              << ". You have "
              << Settings::max_guesses << " tries to guess what it is. " << '\n'; // Settings::max_guesses is 7 by default

    // Actual game starts here
    int guess{0}; // Used to store the player's guess

    // guess_number indicates the number of the guess (eg. Guess #1, Guess#2,...)
    for (int guess_number{1}; guess_number <= Settings::max_guesses; ++guess_number)
    {
        std::cout << "Guess #" << guess_number << ": ";

        // Get input, sanitize cin buffer to avoid issues later.
        std::cin >> guess;
        failureCin();

        // WIN
        if (guess == num)
        {
            std::cout << "Correct! You win!\n";
            return; // return to caller (main)
        }

        // If this is the last guess, the player has lost already
        if (guess_number == Settings::max_guesses)
            break;

        // INCORRECT
        else if (guess >= 1 && guess <= 100) // If you're at the last guess, no need to give more hints.
        {
            std::cout << "Your guess is too " << (guess > num ? "high.\n" : "low.\n");

            continue;
        }

        // If control reaches here, the guess was invalid
        --guess_number;
    }

    std::cout << "Sorry, you lose. The correct number was " << num << '\n';
    return;
}

bool playAgain() // Once an hiLo game is completed, the user is prompted to play the game again.
{
    char playAgain{'n'};
    while (true)
    {
        // Prompt user
        std::cout << "\nWould you like to play again? [y/n]\n";

        // Get input, sanitize cin buffer to avoid issues later.
        std::cin >> playAgain;
        failureCin();

        // Return to caller (main) whether the user wants to keep playing (1) or not (0)
        if (playAgain == 'y' || playAgain == 'Y')
            return 1;

        // By default, stop playing
        return 0;
    }
    return 0;
}

int main()
{
    while (true) // This loop runs the hiLo function until the user chooses to stop playing.
    {
        hiLo();
        if (playAgain())
            continue;
        else
            return 0;
    }
    return 1;
}
