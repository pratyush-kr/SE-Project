class Member
{
    private:
        std::string name;
        std::string id;
        std::string phone_num;
        std::string address;
        const std::string GenerateID();
    public:
        friend std::istream& operator >>(std::istream &, Member &);
        friend std::ostream& operator <<(std::ostream &, const Member &);
};

std::istream& operator >>(std::istream &in, Member &member)
{
    std::cout<<"Name: ";
    std::getline(in, member.name);
    member.id = member.GenerateID();
    std::cout<<"ID: "<<member.id<<'\n';
    std::cout<<"Phone: ";
    in>>member.phone_num;
    std::cout<<"Address: ";
    std::getline(in, member.address);
    return in;
}

const std::string Member::GenerateID()
{
    char ID[5];
    srand(time(0));
    for(int i=0; i<5; i++)
        ID[i] = (char)(rand() % 93 + 48);
    return (const std::string)ID;
}