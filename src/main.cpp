#include <iostream>
#include <string>
#include <vector>
#include "Book.cpp"
#include "Member.cpp"
#include "Library.cpp"
#include <map>

std::map<std::string, Member*> MemberBy;
std::map<std::string, Book*> BookBy;

int main()
{
    std::string command;
    Library myLib("General Lib");
    while(1)
    {
        std::cout<<"Command: ";
        std::getline(std::cin, command);
        if(command == "exit")
            break;
        else if(command == "add book")
            myLib.AddBook();
        else if(command == "show book")
            myLib.ShowBook();
        else if(command == "lend book")
        {
            std::string ISBN, ID;
            std::cout<<"Lend to (ID): ";
            std::cin>>ID;
            std::cout<<"ISBN: ";
            std::cin>>ISBN;
            myLib.LendBook(MemberBy[ID], BookBy[ISBN]);
        }
        else if(command == "return book")
        {
            std::string ISBN, ID;
            std::cout<<"Returnee(ID): ";
            std::cin>>ID;
            std::cout<<"ISBN: ";
            std::cin>>ISBN;
            myLib.ReturnBook(MemberBy[ID], BookBy[ISBN]);
        }
        else if(command == "add member")
            myLib.AddMember();
        else if(command == "remove member")
        {
            std::string ID;
            std::cout<<"MemberID: ";
            std::cin>>ID;
            myLib.RemoveMember(MemberBy[ID]);
        }
    }
    return 0;
}