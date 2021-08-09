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
    printf("For help write: 'help'\n");
    while(1)
    {
        std::cout<<"Command: ";
        std::getline(std::cin, command);
        if(command == "exit")
            break;
        else if(command == "add book")
        {
            Book *book;
            book = myLib.AddBook();
            BookBy[book->ISBN()] = book;
        }
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
        {
            Member *member;
            member = myLib.AddMember();
            MemberBy[member->ID()] = member;
        }
        else if(command == "remove member")
        {
            std::string ID;
            std::cout<<"MemberID: ";
            std::cin>>ID;
            Member *member = MemberBy[ID];
            MemberBy.erase(ID);
            myLib.RemoveMember(member);
        }
        else if(command == "help")
        {
            printf("Commands:\n");
            printf("add book\n");
            printf("add member\n");
            printf("lend book\n");
            printf("remove member\n");
            printf("return book\n");
            printf("show book\n");
        }
        std::cin.ignore();
    }
    return 0;
}