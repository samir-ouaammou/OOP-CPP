#include "Contact.hpp"

Contact::Contact()
{
    FirstName = "";
    LastName = "";
    NickName = "";
    PhoneNumber = "";
    DarkestSecret = "";
}

std::string Contact::GetFirstName()
{
    return (this->FirstName);
}

std::string Contact::GetLastName()
{
    return (this->LastName);
}

std::string Contact::GetNickName()
{
    return (this->NickName);
}

std::string Contact::GetPhoneNumber()
{
    return (this->PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
    return (this->DarkestSecret);
}

void Contact::displaytInfo()
{
    std::cout << "First Name: " << this->FirstName << std::endl;
    std::cout << "Last Name: " << this->LastName << std::endl;
    std::cout << "Nick Name: " << this->NickName << std::endl;
    std::cout << "Phone Number: " << this->PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
}

void    Contact::fillAttributes(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->NickName = NickName;
    this->PhoneNumber = PhoneNumber;
    this->DarkestSecret = DarkestSecret;
}

Contact::~Contact()
{}
