#include "../header_files/constants.h"
#include <iostream>

void decorate(const char text[], const char decorator[])
{
    std::cout << decorator << ' ' << text << ' ' << decorator << std::endl;
}

void menu()
{
    decorate("Available Commands", COMMANDS_DECORATOR);
    std::cout << std::endl;

    std::cout << "--add [source] [password]" << TAB1 << "--> adds to the database"
            << std::endl;
    std::cout << "--view" << TAB2 << "--> retrieves from the database" << std::endl;
    std::cout << "--update [orderNumber] [newSource] [newPassword]" << TAB3
            << "--> updates the database" << std::endl;
    std::cout << "--delete [orderNumber]" << TAB4 << "--> deletes from the database"
            << std::endl;
    std::cout << "--search [source_keyword]" << TAB1 << "--> searches in the database"
            << std::endl;
    std::cout << "--quit" << TAB2 << "--> quits the database" << std::endl;

    std::cout << std::endl;
}
