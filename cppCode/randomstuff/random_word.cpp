#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "failureCin.h"

// The following code takes a list of words and outputs them in a random order

std::string get_word()
{
    std::string output{};
    do
    {
        std::cin >> output;
    } while (failureCin());

    return output;
}

int main()
{
    std::vector<std::string> words{};

    // Nested block to get all inputs
    {
        std::string word;
        do
        {
            std::cout << "Type the next word or !STOP! to stop: ";
            std::getline(std::cin, word, '\n');
            words.insert(words.end(), word);
        } while (word != "!STOP!");
        words.erase(words.end() - 1);
    }

    // Shuffle them words
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(words.begin(), words.end(), g);

    // Output
    for (std::string word : words)
        std::cout << word << "\n";
    
    return 0;
}
