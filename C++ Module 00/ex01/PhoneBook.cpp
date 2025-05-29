# include "PhoneBook.hpp"

std::string PhoneBook::GetContactFirstName(short Index)
{
    return (this->Contacts[Index].GetFirstName());
}

std::string PhoneBook::GetContactLastName(short Index)
{
    return this->Contacts[Index].GetLastName();
}

std::string PhoneBook::GetContactNickName(short Index)
{
    return (this->Contacts[Index].GetNickName());
}

std::string PhoneBook::GetContactPhoneNumber(short Index)
{
    return (this->Contacts[Index].GetPhoneNumber());
}

std::string PhoneBook::GetContactDarkestSecret(short Index)
{
    return (this->Contacts[Index].GetDarkestSecret());
}

void PhoneBook::displayContacts(short index)
{
    this->Contacts[index].displaytInfo();
}
void PhoneBook::displayContactInfo(short Index)
{
    this->Contacts[Index].displaytInfo();
}
Contact PhoneBook::GetContacts(short index)
{
    return this->Contacts[index];
}
void PhoneBook::AddContacts(short Index, std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
    this->Contacts[Index].fillAttributes(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
}

void PhoneBook::displayPhoneInfo(short Index, std::string FirstName, std::string LastName, std::string NickName)
{
    std::string  temp;

    std::cout << '*' << std::setw(10) << std::right << Index << '|';
    if (FirstName.length() > 10)
        temp = FirstName.substr(0, 9) + '.';
    else
        temp = FirstName;
    std::cout << std::setw(10) << std::right << temp << '|';
    
    if (LastName.length() > 10)
        temp = LastName.substr(0, 9) + '.';
    else
        temp = LastName;
    std::cout << std::setw(10) << std::right << temp << '|';
    
    if (NickName.length() > 10)
        temp = NickName.substr(0, 9) + '.';
    else
        temp = NickName;
    std::cout << std::setw(10) << std::right << temp << '*' << std::endl;
}