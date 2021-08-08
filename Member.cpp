class Member
{
    private:
        std::string member_name;
        std::string member_id;
        std::string phone_num;
        std::string address;
    public:
        friend std::istream& operator >>(std::istream &, Member &);
        friend std::ostream& operator <<(std::ostream &, const Member &);
};