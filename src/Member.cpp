class Member
{
    private:
        std::string name;
        std::string id;
        std::string phone_num;
        std::string address;
        const std::string GenerateID();
    public:
        std::vector<Book*> Borrowed;
        friend std::istream& operator >>(std::istream &, Member *);
        friend std::ostream& operator <<(std::ostream &, const Member &);
};

std::istream& operator >>(std::istream &in, Member *member)
{
    std::cout<<"Name: ";
    in.ignore();
    std::getline(in, member->name);
    member->id = member->GenerateID();
    MemberbyID[member->id] = member;
    std::cout<<"ID: "<<member->id<<'\n';
    std::cout<<"Phone: ";
    in>>member->phone_num;
    std::cout<<"Address: ";
    in.ignore();
    std::getline(in, member->address);
    return in;
}

std::ostream& operator <<(std::ostream &out, const Member &member)
{
    out<<"Member Name: "<<member.name<<'\n';
    out<<"ID: "<<member.id<<'\n';
    out<<"Phone: "<<member.phone_num<<'\n';
    out<<"Address: "<<member.address<<'\n';
    return out;
}

const std::string Member::GenerateID()
{
    char ID[6];
    srand(time(0));
    for(int i=0; i<5; i++)
        ID[i] = (char)(rand() % 93 + 47);
    ID[5] = '\0';
    return (const std::string)ID;
}