#include "../header_files/database.h"

#include <iostream>
#include <cstring>

bool kmpSearch(const char* string1, const char* string2) {
    size_t length1 = strlen(string1);
    size_t length2 = strlen(string2);
    int maxPrefixLength[SOURCE_DIM];

    maxPrefixLength[0] = 0;
    int currPrefixLength = 0;
    for (int i = 1; i < length1; i++) {
        while (currPrefixLength != 0 && string1[i] != string1[currPrefixLength])
            currPrefixLength = maxPrefixLength[currPrefixLength - 1];

        if (string1[i] == string1[currPrefixLength])
            currPrefixLength++;
        maxPrefixLength[i] = currPrefixLength;
    }

    currPrefixLength = 0;
    for (int i = 0; i < length2; i++) {
        while (currPrefixLength != 0 && string2[i] != string1[currPrefixLength])
            currPrefixLength = maxPrefixLength[currPrefixLength - 1];

        if (string2[i] == string1[currPrefixLength])
            currPrefixLength++;

        if (currPrefixLength == length1)
            return true;
    }

    return false;
}

void search() {
    char searchedKeyword[SOURCE_DIM];
    std::cin >> searchedKeyword;

    if (stringIsValid(searchedKeyword)) {
        cell resultDatabase[DATABASE_DIM];
        int resultCnt = 0;

        // KMP - Knuth-Morris-Pratt String-Searching Algorithm
        for (int i = 1; i <= cnt; i++) {
            bool keywordIsFound = kmpSearch(searchedKeyword, database[i].source);
            if (keywordIsFound)
                resultDatabase[++resultCnt] = database[i];
        }

        view(resultDatabase, resultCnt);
    } else
        invalidInput();
}