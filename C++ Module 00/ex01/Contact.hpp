#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class   Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNumber;
        std::string _DarkestSecret;

    public:
        Contact();
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();
        void        displaytInfo();
        void        fillAttributes(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
        ~Contact();
};

#endif