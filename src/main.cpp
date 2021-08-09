#include <iostream>
#include <string>
#include <vector>
#include "Book.cpp"
#include "Member.cpp"
#include "Library.cpp"
#include <map>

std::map<std::string, Member*> MemberbyID;
std::map<std::string, Book*> BookbyISBN;

int main()
{
    Library myLib("General Lib");
    myLib.AddBook();
    printf("\n");
    myLib.AddMember();
    printf("THE BOOK\n");
    myLib.ShowBook();
    printf("THE MEMBER\n");
    myLib.ShowMember();
    return 0;
}