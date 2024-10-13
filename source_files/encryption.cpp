#include "../header_files/database.h"

#include <fstream>
#include <algorithm>

void readFile()
{
    std::ifstream fin(PATH);
    do
    {
        cnt++;
    }
    while (fin >> database[cnt].source >> database[cnt].password);
    cnt--;
    fin.close();
}

void encrypt()   // ROT13 encryption
{
    std::ofstream fout(PATH);

    for (int i = 1; i <= cnt; i++)
    {
        char source[SOURCE_DIM], password[PASSWORD_DIM];
        std::strcpy(source, database[i].source);
        std::strcpy(password, database[i].password);

        // encrypting source
        for (int j = 0; source[j]; j++)
        {
            if (source[j] >= 33 && source[j] <= 113)
                fout << static_cast<char>(source[j] + 13);
            else
                fout << static_cast<char>(source[j] - 81);
        }

        fout << ' ';

        // encrypting password
        for (int j = 0; password[j]; j++)
        {
            if (password[j] >= 46 && password[j] <= 126)
                fout << static_cast<char>(password[j] - 13);
            else
                fout << static_cast<char>(password[j] + 81);
        }

        fout << '\n';
    }
    fout.close();
}

void decrypt()  // ROT13 decryption
{
    readFile();

    for (int i = 1; i <= cnt; i++)
    {
        char source[SOURCE_DIM], password[PASSWORD_DIM];
        std::strcpy(source, database[i].source);
        std::strcpy(password, database[i].password);

        // decrypting source
        size_t sourceLength = std::strlen(source);
        for (int j = 0; j < sourceLength; j++)
        {
            if (source[j] >= 46 && source[j] <= 126)
                database[i].source[j] = static_cast<char>(source[j] - 13);
            else
                database[i].source[j] = static_cast<char>(source[j] + 81);
        }
        database[i].source[sourceLength] = 0;

        // decrypting password
        size_t passwordLength = std::strlen(password);
        for (int j = 0; j < passwordLength; j++)
        {
            if (password[j] >= 33 && password[j] <= 113)
                database[i].password[j] = static_cast<char>(password[j] + 13);
            else
                database[i].password[j] = static_cast<char>(password[j] - 81);
        }
        database[i].password[passwordLength] = 0;
    }
}