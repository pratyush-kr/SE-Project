class Library
{
    private:
        std::string library_name;
        std::vector<Book*> books;
        std::vector<Member*> members;
    public:
        void AddBook();
        void AddMember();
};

void Library::AddBook()
{
    Book *book = new Book;
    std::cin>>*book;
    books.push_back(book);
}

void Library::AddMember()
{
    Member *member = new Member;
    std::cin>>*member;
    members.push_back(member);
}