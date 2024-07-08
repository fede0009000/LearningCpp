#include <iostream>
#include <Random.h>
#include <vector>
#include <string_view>

// WORD LIST ___________________________________________________________________________________________________________________________
namespace WordList
{
    const std::vector<std::string> words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, (words.size() - 1))];
    }
}

// FIND IN ARRAY ______________________________________________________________________________________________________________________
bool findGuess(const std::vector<char> &vec, char value)
{
    for (char i : vec)
        if (i == value)
            return true;
    return false;
}
bool findGuess(std::string_view str, char value)
{
    for (char i : str)
        if (i == value)
            return true;
    return false;
}

// SESSION INFORMATION ________________________________________________________________________________________________________________
class Session
{
private:
    std::string_view m_word{WordList::getRandomWord()};
    std::vector<char> m_guesses;
    int m_wrongGuesses{0};

public:
    std::string_view getWord() const { return m_word; }
    const std::vector<char> &getGuesses() const { return m_guesses; }
    int getWrongGuesses() const { return m_wrongGuesses; }

    void addGuess(char guess)
    {
        if (!findGuess(m_word, guess))
        {
            ++m_wrongGuesses;
        }
        m_guesses.push_back(guess);
    }

    bool beenGuessed(char guess) const { return findGuess(m_guesses, guess); }

    void printGuessesLeft() const
    {
        std::cout << "Guesses: ";

        for (int i{6}; i > 0; --i)
        {
            if (i > m_wrongGuesses)
                std::cout << '+';
            else
                std::cout << m_guesses[m_wrongGuesses - i];
        }
    }

    void checkWin(bool &won)
    {
        won = true;
        for (char i : m_word)
        {
            if (!findGuess(m_guesses, i))
                won = false;
        }
    }
};

// PRINT STATE _________________________________________________________________________________________________________________
void printState(const Session &s)
{
    // print word
    std::cout << '\n';
    std::cout << "The word: ";
    for (char i : s.getWord())
    {
        if (s.beenGuessed(i))
        {
            std::cout << i;
        }
        else
        {
            std::cout << '_';
        }
    }
    std::cout << "  ";
    s.printGuessesLeft();
    std::cout << '\n';
}

// GET INPUT ___________________________________________________________________________________________________________________________
char getInput(const Session &s)
{
    char input{};
    while (true)
    {
        std::cout << "Enter your next letter: ";
        std::cin >> input;
        if (!std::cin || input < 'a' || input > 'z')
        {
            // Fix invalid input
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (s.beenGuessed(input))
        {
            std::cout << "You already guessed that. Try again." << '\n';
            continue;
        }

        break;
    }
    return input;
}

// MAIN _______________________________________________________________________________________________________________________________
int main()
{
    std::cout << "Welcome to Textman (a variation of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n";
    Session session{};
    printState(session);
    bool won{false};
    while (session.getWrongGuesses() < 6 && !won)
    {
        won = true;
        session.addGuess(getInput(session));
        printState(session);
        session.checkWin(won);
    }
    if (session.getWrongGuesses() == 6)
        std::cout << "You lost! The correct word was " << session.getWord();
    else
        std::cout << "You won!";
}
