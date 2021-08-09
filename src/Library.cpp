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
    if(books.size() > 0)
        std::cout<<*books[0]<<'\n';
    else
        std::cout<<"No Books available\n";
}

void Library::ShowMember()
{
    if(books.size() > 0)
        std::cout<<*members[0]<<'\n';
    else
        std::cout<<"No Members available\n";
}

void Library::LendBook(Member *member, Book *book)
{
    if(!member)
    {
        std::cout<<"Member not available\n";
        return;
    }
    if(!book)
    {
        std::cout<<"No book registered with this ISBN\n";
        return;
    }
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
    if(!member)
    {
        std::cout<<"Member not available\n";
        return;
    }
    if(!book)
    {
        std::cout<<"No book registered with this ISBN\n";
        return;
    }
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
    if(member)
    {
        for(int i=0; i<members.size(); i++)
            if(members[i] == member)
            {
                printf("Deleted Member %s sucessfully\n", (char*)&(member->Name())[0]);
                delete member;
                members.erase(members.begin() + i);
                return;
            }
    }
    else
        std::cout<<"No member with this PID\n";
}