#include "../header_files/constants.h"
#include "../header_files/database.h"

#include <iostream>
#include <cstring>

cell database[DATABASE_DIM];
int cnt = 0;

bool execute()
{
    char command[STRING_DIM];
    std::cin >> command;

    if (std::strcmp(command, "add") == 0)
        add();
    else if (std::strcmp(command, "view") == 0)
        view(database, cnt);
    else if (std::strcmp(command, "update") == 0)
        update();
    else if (std::strcmp(command, "delete") == 0)
        del();
    else if (std::strcmp(command, "search") == 0)
        search();
    else if (std::strcmp(command, "quit") == 0)
    {
        quitDatabase();
        return false;
    }
    else
        unknownCommand();

    return true;
}

int main()
{
    system("clear");
    decorate("Password Database", HEADING_DECORATOR);

    std::cout << "Press enter to continue: ";
    std::cin.get();

    decrypt();
    do
    {
        system("clear");
        menu();
    }
    while (execute());
    encrypt();

    system("clear");
    return 0;
}
