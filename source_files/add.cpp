#include "../header_files/database.h"

#include <iostream>
#include <cstring>

void add()
{
    char source[SOURCE_DIM], password[PASSWORD_DIM];
    std::cin >> source >> password;

    if (isInDatabase(source))
    {
        inDatabaseInput();
        return;
    }

    if (stringIsValid(source) && stringIsValid(password) && bufferIsEmpty())
    {
        ++cnt;
        std::strcpy(database[cnt].source, source);
        std::strcpy(database[cnt].password, password);
    }
    else
        invalidInput();
}