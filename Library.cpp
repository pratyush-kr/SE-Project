class Library
{
    private:
        std::string name;
        std::vector<Book*> books;
        std::vector<Member*> members;
    public:
        void AddBook();
        void AddMember();
        void ShowBook();
        void ShowMember();
        Library() {}
        Library(const std::string &name)
        {
            this->name = name;
        }
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

void Library::ShowBook()
{
    std::cout<<*books[0]<<'\n';
}

void Library::ShowMember()
{
    std::cout<<*members[0]<<'\n';
}