#include <iostream>
#include "Random.h"
#include <limits>

void ignoreLine() // for error handling
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ignoreLine();

void hiLo() {
    int guess{0};
    int num{0};
    for(int tryn{1}; tryn <= 7; ++tryn) {

        
        num = Random::get(1,100);
        
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. " << '\n';

        while(true) {
            if(tryn > 7) {
                std::cout << "Sorry, you lose. The correct number was " << num << '\n';
                return;
            }

            std::cout << "Guess #" << tryn << ": " << '\n';

            std::cin >> guess;

            if(std::cin.peek() != '\n') {
                std::cin.clear();
                ignoreLine();
                continue;
            }

            if(guess==num) {
                std::cout << "Correct! You win!\n";
                return;
            }
            else if(guess >= 1 && guess <= 100) {
                std::cout << "Your guess is too " << (guess > num ? "high" : "low") << '\n';
                ++tryn;
            }
            
            std::cin.clear();
            ignoreLine();

            continue;
            
        }
    }
}

bool playAgain() {
    char playAgain{'n'};
    while(true) {
        std::cout << "Would you like to play again (y/n)? " << '\n';
        std::cin >> playAgain;
        
        if(std::cin.peek() != '\n') {
                std::cin.clear();
                ignoreLine();
                continue;
            }
        std::cin.clear();
        ignoreLine();

        switch(playAgain) {
            case 'y': return 1;
            case 'n': return 0;
        }
    }
    return 0;
}

int main() {
    while(true) {
        hiLo();
        if(playAgain()) continue;
        else return 0;
    }
    return 1;
}
