#include <iostream>

int main()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int length{static_cast<int>(std::size(array))};

    for (int i{0}; i + 2 < length; ++i)
    {
        bool swap{false};
        for (int j{0}; j + 1 < length - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swap = true;
            }
        }
        if (!swap)
            break;
        else
            swap = false;
    }

    // print
    for (int index{0}; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
