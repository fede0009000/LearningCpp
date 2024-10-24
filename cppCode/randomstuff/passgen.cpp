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
    std::cout << "Insert password length: ";
    int length{};
    do
    {
        std::cin >> length;
    } while (failureCin() || length < 1);

    // UPPERCASE
    std::cout << "Do you want the password to contain uppercase letters? [Y/n]";
    if (getYnInput())
        possibleChars.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // LOWERCASE
    std::cout << "Do you want the password to contain lowercase letters? [Y/n]";
    if (getYnInput())
        possibleChars.append("abcdefghijklmnopqrstuvwxyz");

    // SYMBOLS
    std::cout << "Do you want the password to contain symbols (eg. punctuation)? [Y/n]";
    if (getYnInput())
        possibleChars.append("!\"#$%&'()*+, -./:;<=>?@[\\]^_`{|}~");

    // PASSWORD GENERATOR
    std::string password{""};
    const int possibleCharsLen{static_cast<int>(possibleChars.size())};
    for (int i{0}; i < length; ++i) {
        password += possibleChars[Random::get(0, possibleCharsLen - 1)];
    }

    std::cout << "Here is your new password: " << password;
}
