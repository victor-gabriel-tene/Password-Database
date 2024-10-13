#include "../header_files/constants.h"
#include "../header_files/database.h"

#include <iostream>
#include <cstring>

bool isInDatabase(char s[])
{
    for (int i = 1; i <= cnt; i++)
        if (std::strcmp(database[i].source, s) == 0)
            return true;
    return false;
}

void lower(char s[])
{
    for (int index = 0; s[index]; index++)
        if (s[index] >= 'a' && s[index] <= 'z')
            s[index] -= 32;
}

bool alphaSort(cell a, cell b)
{
    lower(a.source), lower(b.source);
    return std::strcmp(a.source, b.source) < 0;
}

bool stringIsValid(const char s[])
{
    for (int index = 0; s[index]; index++)
        if (!(s[index] >= 33 && s[index] <= 126))
            return false;
    return true;
}

int isNumber(const char s[])
{
    int result = 0;
    for (int index = 0; s[index]; index++)
    {
        if (s[index] >= '0' && s[index] <= '9')
            result = result * 10 + (s[index] - '0');
        else
            return -1;
    }
    return result;
}

bool bufferIsEmpty()
{
    return std::cin.get() == '\n';
}

void clearBuffer()
{
    char buffer[BUFFER_DIM];
    std::cin.getline(buffer, BUFFER_DIM);
}

void quitDatabase()
{
    std::cout << std::unitbuf << "Quitting Database";
}

void unknownCommand()
{
    clearBuffer();
    std::cout << std::unitbuf << "Unknown Command";
}

void invalidInput()
{
    clearBuffer();
    std::cout << std::unitbuf << "Invalid Input";
}

void inDatabaseInput()
{
    clearBuffer();
    std::cout << std::unitbuf << "Already In The Database";
}