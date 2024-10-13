#include "../header_files/constants.h"
#include "../header_files/database.h"

#include <iostream>

void update()
{
    char orderNumber[STRING_DIM], source[SOURCE_DIM], password[PASSWORD_DIM];
    std::cin >> orderNumber >> source >> password;

    int result = isNumber(orderNumber);
    if ( (stringIsValid(source) && stringIsValid(password)) &&
         (result >= 1 && result <= cnt) &&
         bufferIsEmpty() )
    {
        std::strcpy(database[result].source, source);
        std::strcpy(database[result].password, password);
    }
    else
        invalidInput();
}