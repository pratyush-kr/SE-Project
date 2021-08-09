class Book
{
    private:
        std::string name;
        std::string isbn;
        std::string author_name;
        unsigned int pages;
        float price;
        unsigned int quantity;
    public:
        std::vector<Member*> Borrowers;
        friend std::istream& operator >>(std::istream &, Book *); //Use Address before assigning any Refference
        friend std::ostream& operator <<(std::ostream &, const Book &);
        int Qunatity() {return quantity--;}
        void ReturnBook() {quantity++;}
        void LendBook() {quantity--;}
        std::string Name() {return name;}
};

std::istream& operator >>(std::istream &in, Book *book)
{
    std::cout<<"Book Name: ";
    std::getline(in, book->name);
    std::cout<<"ISBN: ";
    in>>book->isbn;
    BookBy[book->isbn] = book;
    std::cout<<"Author Name: ";
    in.ignore();
    std::getline(in, book->author_name);
    std::cout<<"Pages: ";
    in>>book->pages;
    std::cout<<"Price: ";
    in>>book->price;
    std::cout<<"Quantity: ";
    in>>book->quantity;
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