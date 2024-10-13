#include "../header_files/database.h"
#include "../header_files/constants.h"

#include <cstring>
#include <iostream>

size_t getLongestString(cell toView[], int size)
{
    size_t result = 0;
    for (int i = 1; i <= size; i++)
        result = std::max(result, std::strlen(toView[i].source));
    return result;
}

size_t getIntegerLength(int n)
{
    size_t result = 0;
    while (n)
        result++, n /= 10;
    return result;
}

void printChar(char ch, size_t n)
{
    for (size_t i = 1; i <= n; i++)
        std::cout << ch;
}

void view(cell toView[], int size)
{
    if (!bufferIsEmpty())
    {
        invalidInput();
        return;
    }
    system("clear");
    std::sort(toView + 1, toView + size + 1, alphaSort);

    // Header
    const size_t numOfSpaces = getLongestString(toView, size);
    const size_t finalSpace = numOfSpaces + DIST;
    const size_t space = finalSpace + numOfSpaces - std::strlen("SOURCE");

    std::cout << "ID", printChar('-', finalSpace - 1);
    std::cout << "SOURCE", printChar('-', space);
    std::cout << "PASSWORD" << std::endl;

    // Content
    for (int i = 1; i <= size; i++)
    {
        const size_t INTspace = finalSpace - getIntegerLength(i) + 1;
        const size_t STRINGspace = finalSpace + numOfSpaces
                - std::strlen(toView[i].source);

        std::cout << i, printChar(' ', INTspace);
        std::cout << toView[i].source, printChar(' ', STRINGspace);
        std::cout << toView[i].password << std::endl;
    }

    std::cout << std::endl << "Press ENTER to exit VIEW mode: ";
    std::cin.get();
}