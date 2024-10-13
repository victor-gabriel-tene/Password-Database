#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H

// Important database constants
#define SOURCE_DIM 101
#define PASSWORD_DIM 101
#define DATABASE_DIM 1001

// Database file path
#define PATH "../data.txt"

// Database storage
extern struct cell
{
    char source[SOURCE_DIM], password[PASSWORD_DIM];
} database[DATABASE_DIM];
extern int  cnt;

// Database sorting function
bool alphaSort(cell, cell);

// Database UI menu
void decorate(const char text[], const char decorator[]);
void menu();

// Database encryption
void readFile();
void encrypt();
void decrypt();

// Database functions
void add();
void view(cell [], int);
void update();
void del();
void search();

// Database additional functions
bool isInDatabase(char []);
void lower(char []);
int isNumber(const char []);
bool stringIsValid(const char []);
bool bufferIsEmpty();
void clearBuffer();
void unknownCommand();
void invalidInput();
void quitDatabase();
void inDatabaseInput();

#endif