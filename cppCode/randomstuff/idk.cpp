#include <cassert>
#include <iostream>
#include <vector>

namespace Items{
    enum ItemsEnum{
        health_potion,
        torch,
        arrow,
        max_items
    };
}

std::string getItemP(Items::ItemsEnum item) {
    using Items::ItemsEnum;
    switch(item) {
        case 0: return "health potions";
        case 1: return "torches";
        case 2: return "arrows";
        default: return "???";
    }

}

std::string getItemS(Items::ItemsEnum item) {
    using Items::ItemsEnum;
    switch(item) {
        case 0: return "health potion";
        case 1: return "torch";
        case 2: return "arrow";
        default: return "???";
    }

}

int count(const std::vector<int>& v) {
    int temp{0};
    for(int i : v) temp += i;
    return temp;
}

void printInventory(const std::vector<int>& inv) {
    for(std::size_t i{0}; i < inv.size(); ++i) {
        std::cout << "You have " << inv[i] << ' ' << (inv[i] > 1 ? getItemP(static_cast<Items::ItemsEnum>(i)) : getItemS(static_cast<Items::ItemsEnum>(i))) << ".\n";
    }
    std::cout << "You have " << count(inv) << " total items.";
}

int main() {
    std::vector<int> inventory( Items::max_items );
    assert(inventory.size() == Items::max_items);
    inventory = {1, 5, 10};

    printInventory(inventory);
}
