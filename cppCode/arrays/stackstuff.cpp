#include <iostream>
#include <vector>

void printStack(std::vector<int> &vector)
{

    std::cout << "\t(Stack: ";
    if (vector.empty())
        std::cout << "empty)\n";
    else
    {
        for (int i : vector)
            std::cout << i << ' ';
        std::cout << ')' << '\n';
    }

    return;
}

void pushAndPrint(std::vector<int> &vector, int num)
{

    vector.push_back(num);
    std::cout << "Push " << num << ' ';

    printStack(vector);
    return;
}

void popAndPrint(std::vector<int> &vector)
{

    if (vector.size() == 0)
        return;

    vector.pop_back();
    std::cout << "Pop   ";

    printStack(vector);
    return;
}

int main()
{
    std::vector<int> v{};
    printStack(v);

    pushAndPrint(v, 1);
    pushAndPrint(v, 2);
    pushAndPrint(v, 3);
    popAndPrint(v);
    pushAndPrint(v, 4);
    popAndPrint(v);
    popAndPrint(v);
    popAndPrint(v);
    popAndPrint(v);
    popAndPrint(v);
}
