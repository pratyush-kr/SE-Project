#include "Book.cpp"
#include "Member.cpp"
class Library
{
    private:
        Book *books;
        Member *members;
    public:
        Library()
        {
            books = new Book;
            members = new Member;
        }
};