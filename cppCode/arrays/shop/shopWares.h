#ifndef SHOPWARES
#define SHOPWARES

#include <array>
#include <string_view>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types{healing, mana, speed, invisibility};

    constexpr std::array<std::string_view, max_potions> name{"healing", "mana", "speed", "invisibility"};
    constexpr std::array cost{20, 30, 12, 50};

    static_assert(std::size(types) == max_potions);
    static_assert(std::size(cost) == max_potions);
    static_assert(std::size(name) == max_potions);
}

#endif
