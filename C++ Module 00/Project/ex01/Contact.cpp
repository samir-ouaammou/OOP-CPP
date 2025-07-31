#include "Contact.hpp"

Contact::Contact() : _FirstName(""), _LastName(""), _NickName(""), _PhoneNumber(""), _DarkestSecret("")
{
}

std::string Contact::GetFirstName()
{
    return (_FirstName);
}

std::string Contact::GetLastName()
{
    return (_LastName);
}

std::string Contact::GetNickName()
{
    return (_NickName);
}

std::string Contact::GetPhoneNumber()
{
    return (_PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
    return (_DarkestSecret);
}

void Contact::displaytInfo()
{
    std::cout << "First Name: " << _FirstName << std::endl;
    std::cout << "Last Name: " << _LastName << std::endl;
    std::cout << "Nick Name: " << _NickName << std::endl;
    std::cout << "Phone Number: " << _PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _DarkestSecret << std::endl;
}

void    Contact::fillAttributes(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
    _FirstName = FirstName;
    _LastName = LastName;
    _NickName = NickName;
    _PhoneNumber = PhoneNumber;
    _DarkestSecret = DarkestSecret;
}

Contact::~Contact()
{}
