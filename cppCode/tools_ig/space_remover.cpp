#include <iostream>
#include <string>
#include "failureCin.h"

void remove_spaces(std::string& text)
{
    std::size_t len{text.length()};
    int space_counter{0};
    char currC{};
    for (std::size_t i{0}; i < len; ++i)
    {
        currC = text[i];

        if(std::isspace(currC))
            space_counter += 1;
        else
            space_counter = 0;
        
        if(space_counter > 1)
        {
            text.erase(text.begin() + static_cast<long long>(i));
            space_counter = 0;
        }

        // Remove dashes for newlines
        if (currC == '-')
        {
            text.erase(text.begin() + static_cast<long long>(i));
            text.erase(text.begin() + static_cast<long long>(i));
            continue;
        }
    }
}

int main()
{
    std::string text{};
    std::string input{};

    std::cout << "Please enter the text with useless spaces you want to remove. It must end with __STOP__ or an empty line.\n";
    while(true)
    {
        std::getline(std::cin, input);

        if (input == "__STOP__" || input.empty())
            break;
        
        if (std::isspace(*(input.end()-1)))
        {
            input.erase(input.end() - 1);
            text.append(input);
            continue;
        }
            
        text.append(' ' + input);
    } 

    remove_spaces(text);

    std::cout << "\n--------------------------------------------\n";
    std::cout << "Here is your text without superflous spaces:\n\n\n" << text;

    return 0;
}
