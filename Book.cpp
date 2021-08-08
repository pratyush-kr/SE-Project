#include<iostream>
class Book
{
    private:
        std::string book_name;
        std::string isbn;
        std::string author_name;
        unsigned int pages;
        float price;
    public:
        friend std::istream& operator >>(std::istream &, Book &);
        friend std::ostream& operator <<(std::ostream &, const Book &);
};

std::istream& operator >>(std::istream &in, Book &book)
{
    std::cout<<"Book Name: ";
    std::getline(in, book.book_name);
    std::cout<<"ISBN: ";
    in>>book.isbn;
    std::cout<<"Author Name: ";
    std::getline(in, book.author_name);
    std::cout<<"Pages: ";
    in>>book.pages;
    std::cout<<"Price: ";
    in>>book.price;
    return in;
}

std::ostream& operator <<(std::ostream &out, const Book &book)
{
    printf("Book Name: %s\n", book.book_name);
    printf("ISBN: %s\n", book.isbn);
    printf("Author: %s\n", book.author_name);
    printf("Pages: %d\n", book.pages);
    printf("Price: ₹%.2f\n", book.price);
    std::cout<<book.price<<'\n';
}