//credit to learncpp.com for this exercise (and many others)
#include <iostream>
#include "failureCin.h"
#include "Random.h"
#include "shopWares.h"

void printShop(); //from shopWares.cpp
class Player{
private:
    std::string m_name {};
    int m_gold{Random::get(80, 120)};
    std::array <int, Potion::max_potions> m_inv {};

public:
//constructor
    Player() = default;

//getters
    std::string_view getName() const {return m_name;}
    int getGold() const {return m_gold;}
    int getInventory(Potion::Type i) const {return m_inv[i];}

//setters
    void setName(const std::string& name) {m_name = name;}
    void setGold(int gold) {m_gold = gold;}
    void addPotion(Potion::Type i) {++m_inv[i];}

    void printInv();
};
//global data
Player data{};

void getAndSetName() {
    std::string name{};
    
    while(true) {
        std::cout << "Enter your name: ";
        std::cin >> name;
        if(!failureCin()) {
            data.setName(name);
            return;
        };
    }
}

char getInput() {
    char i{};
    while(true) {
        std::cin >> i;
        if(failureCin() || (i >= static_cast<int>(Potion::max_potions + '0') && i != 'q')) {
            std::cout << "That's an invalid input. Try again:";
            continue;
        }
        else return i;
    }
}

void Player::printInv() {
    std::cout << "\nYour inventory contains:\n";
    
    for(int i{0}; i < std::size(m_inv); ++i) {
        if(!m_inv[i]) continue;
        else {
            std::cout << m_inv[i] << "x potion of " << Potion::name[i] << '\n';
        }
    }

    std::cout << "You escaped with " << data.getGold() << " gold remaining.\n";
}

int main() {
    std::cout << "Welcome to Roscoe's potion emporium!" << '\n';
    getAndSetName();
    std::cout << "Hello, " << data.getName() << ", you have " << data.getGold() << " gold.\n\n";
    
    char inputChar{};
    int input{};
    while(true) {
        printShop();

        inputChar = getInput();
        if(inputChar == 'q') {
            std::cout << '\n';
            break;
        }
        input = inputChar - '0';
        if(Potion::cost[input] > data.getGold()) {
            std::cout << "You cannot afford that.\n\n";
            continue;
        }
        else {
            data.setGold(data.getGold() - Potion::cost[input]);
            data.addPotion(static_cast<Potion::Type>(input));
            std::cout << "You purchased a potion of " << Potion::name[input] << ". You have " << data.getGold() << " gold left.\n";
        }

        std::cout << '\n';
    }

    data.printInv();
    std::cout << "\nThanks for shopping at Roscoe's emporium!\n";
    return 0;
}
