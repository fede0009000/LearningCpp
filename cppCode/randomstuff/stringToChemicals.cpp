#include <iostream>
#include <array>
#include <string>

constexpr std::array elements{
    "H", "He",                                  //2
    "Li", "Be", "B", "C", "N", "O", "F", "Ne",  //10
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",    //18
    "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",   //36
    "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",   //54
    "Cs", "Ba",                                 //56
    "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", //70
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",  //86
    "Fr", "Ra", //88
    "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",    //103
    "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og",   //118  
};

// MAKE RECURSIVE WORKS BETTER
int main()
{   
    std::string str{};
    std::cout << "\nInsert the word you want to translate to chemical elements: ";
    std::cin >> str;

    std::size_t strlength{str.length()};
    std::string output{};
    // for each character in the string
    for (std::size_t i{0}; i < strlength; ++i)
    {
        // for each element
        for (std::string element : elements)
        {
            bool good{false};
            // for each letter in an element
            std::size_t j{0};
            for (; j < element.length(); ++j)
            {
                if (str[i + j] == element[j])
                    good = true;
                else good = false;

            }

            if (good)
            {
                output.append(element);
                if (j > 1)
                    ++i;
                break;
            }
            if (!good && element == "Og") 
            {
                output = "";
                i = 0;
                break;
            }
        }
    }

    std::cout << output;
}