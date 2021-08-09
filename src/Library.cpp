class Library
{
    private:
        std::string name;
        std::vector<Book*> books;
        std::vector<Member*> members;
    public:
        Book* AddBook();
        Member* AddMember();
        void ShowBook();
        void ShowMember();
        void LendBook(Member*, Book*);
        void RemoveMember(Member *);
        void ReturnBook(Member*, Book*);
        Library() {}
        Library(const std::string &name)
        {
            this->name = name;
        }
};

Book* Library::AddBook()
{
    Book *book = new Book;
    std::cin>>book;
    books.push_back(book);
    return book;
}

Member* Library::AddMember()
{
    Member *member = new Member;
    std::cin>>member;
    members.push_back(member);
    return member;
}

void Library::ShowBook()
{
    std::cout<<*books[0]<<'\n';
}

void Library::ShowMember()
{
    std::cout<<*members[0]<<'\n';
}

void Library::LendBook(Member *member, Book *book)
{
    if(book->Qunatity() > 0) //Book->Quantity Checks for Quantity and reduces it by 1 and returns the present stock
    {
        book->LendBook();
        member->Borrowed.push_back(book);
        book->Borrowers.push_back(member);
        printf("Lended %s to %s: ", (char*)&(book->Name())[0], (char*)&(member->Name())[0]);
        return;
    }
    std::cout<<"Book Not Available\n";
}

void Library::ReturnBook(Member *member, Book *book)
{
    for(int i=0; i<member->Borrowed.size(); i++)
        if(book == member->Borrowed[i])
        {
            printf("Book %s returned sucessfully\n", (char*)&(book->Name())[0]);
            member->Borrowed.erase(member->Borrowed.begin()+i);
            book->ReturnBook();
            return;
        }
}

void Library::RemoveMember(Member *member)
{
    for(int i=0; i<members.size(); i++)
        if(members[i] == member)
        {
            printf("Deleted Member %s sucessfully\n", (char*)&(member->Name())[0]);
            members.erase(members.begin() + i);
            return;
        }
}