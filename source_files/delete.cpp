#include "../header_files/constants.h"
#include "../header_files/database.h"

#include <iostream>

void del()
{
    char orderNumber[STRING_DIM];
    std::cin >> orderNumber;

    int result = isNumber(orderNumber);
    if (result >= 1 && result <= cnt && bufferIsEmpty())
    {
        for (int index = result; index <= cnt; index++)
            database[index] = database[index + 1];
        cnt--;
    }
    else
        invalidInput();
}