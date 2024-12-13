#include <iostream>
#include <string>
#include "failureCin.h"

void remove_spaces(std::string& text)
{
    std::size_t len{text.length()};
    int space_counter{0};
    for (std::size_t i{0}; i < len; ++i)
    {
        if(std::isspace(text[i]))
            space_counter += 1;
        else
            space_counter = 0;
        
        if(space_counter > 1)
        {
            text.erase(text.begin() + static_cast<long long>(i));
            space_counter = 0;
        }
    }
}

int main()
{
    std::string text{};
    std::string input{};

    std::cout << "Please enter the text with useless spaces you want to remove. It must end with __STOP__.\n";
    do
    {
        text.append(input);
        std::getline(std::cin, input);
    } while (input != "__STOP__");

    remove_spaces(text);

    std::cout << "\n--------------------------------------------\n";
    std::cout << "Here is your text without superflous spaces:\n\n\n" << text;
}
