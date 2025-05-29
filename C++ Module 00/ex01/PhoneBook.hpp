#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp" 
# include <iostream>
# include <iomanip>

class   PhoneBook
{
    private:
        Contact Contacts[8];
    public:
        std::string GetContactFirstName(short Index);
        std::string GetContactLastName(short Index);
        std::string GetContactNickName(short Index);
        std::string GetContactPhoneNumber(short Index);
        std::string GetContactDarkestSecret(short Index);
        void        displayContacts(short index);
        void        displayContactInfo(short Index);
        Contact     GetContacts(short index);
        void        AddContacts(short Index, std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
        void        displayPhoneInfo(short Index, std::string FirstName, std::string LastName, std::string NickName);        
};

#endif
