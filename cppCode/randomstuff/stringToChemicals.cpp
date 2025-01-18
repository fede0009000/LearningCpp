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

int main()
{   
    std::string str{};
    std::cout << "Insert the word you want to translate to chemical elements: ";
    std::cin >> str;

    int strlength{str.length()};
    for (int i{0}; i < strlength; ++i)
    {
        for (std::string s : elements)
        {
            for (char c : s)
        }
    }
}