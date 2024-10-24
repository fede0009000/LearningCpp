#include <iostream>
#include <string>
#include "failureCin.h"
#include "Random.h"

bool getYnInput()
{
    char input{};
    do
    {
        std::cin >> input;
    } while (failureCin() || (tolower(input) != 'y' && tolower(input) != 'n'));

    return tolower(input) == 'y';
}

int main()
{
    std::string possibleChars{""};
    std::cout << "Password Generator\n\n";

    // LENGTH
    int length{};
    do
    {
        std::cout << "Insert password length: ";
        std::cin >> length;
    } while (failureCin() || length < 1);

    // UPPERCASE
    std::cout << "\nDo you want the password to contain uppercase letters? [Y/n]\n";
    if (getYnInput())
        possibleChars.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // LOWERCASE
    std::cout << "\nDo you want the password to contain lowercase letters? [Y/n]\n";
    if (getYnInput())
        possibleChars.append("abcdefghijklmnopqrstuvwxyz");

    // SYMBOLS
    std::cout << "\nDo you want the password to contain symbols (eg. punctuation)? [Y/n]\n";
    if (getYnInput())
        possibleChars.append("!\"#$%&'()*+, -./:;<=>?@[\\]^_`{|}~");

    // CHECK POSSIBLECHARS ISN'T EMPTY
    if(possibleChars.empty())
    {
        std::cout << "\nThere are no possible characters to build your password. Please try again.\n";
        return 1;
    }

    // PASSWORD GENERATOR
    std::string password{""};
    const int possibleCharsLen{static_cast<int>(possibleChars.size())};
    for (int i{0}; i < length; ++i) {
        password += possibleChars[Random::get(0, possibleCharsLen - 1)];
    }

    std::cout << "\nHere is your new password:\n" << password;
}
