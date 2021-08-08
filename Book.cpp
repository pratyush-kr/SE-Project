class Book
{
    private:
        std::string name;
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
    std::getline(in, book.name);
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
    out<<"Book Name: "<<book.name<<'\n';
    out<<"ISBN: "<<book.isbn<<'\n';
    out<<"Author: "<<book.author_name<<'\n';
    out<<"Pages: "<<book.pages<<'\n';
    out<<"Price: ₹"<<book.price;
    return out;
}