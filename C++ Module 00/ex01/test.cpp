#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cctype>

class   Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
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


short   CheckString(const std::string& str, short nbr)
{
    short   i;

    if (str.empty())
        return (0);
    i = 0;
    if (nbr)
    {
        if (nbr == 1)
        {
            while (i < str.length())
            {
                if (!std::isalpha(str[i]) && !std::isspace(str[i]))
                    return (0); 
                i++;
            }
        }
        i = 0;
        while (i < str.length())
        {
            if (!std::isspace(str[i]))
                return (1); 
            i++;
        }
        return (0);
    }
    else
    {
        while (i < str.length())
        {
            if (!std::isdigit(str[i])) 
                return (0);
            i++;
        }
        return (1);
    }
}

void    Add(std::string &str, std::string msg, int nbr)
{
    while (1)
    {
        std::cout << msg;
        std::getline(std::cin, str);
        if (!CheckString(str, nbr))
        continue;
        else
            break; ;
    }
}

int main(void)
{
    std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret, Input;
    short   Index, i, NbrSearch, ContactNumber;
    PhoneBook   Phone;

    Index = 0;
    ContactNumber = 0;
    while (1)
    {
        std::cout << "Please enter a command. (ADD, SEARCH OR EXIT): ";
        std::getline(std::cin, Input);
        if (Input == "ADD")
        {
            Add(FirstName, "Enter first name: ", 1);
            Add(LastName, "Enter last name: ", 1);
            Add(NickName, "Enter nickname: ", 1);
            Add(PhoneNumber, "Enter phone number: ",0);
            Add(DarkestSecret, "Enter darkest secret: ",2);
            if (Index == 8)
                Index = 0;
            Phone.AddContacts(Index, FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
            Index++;
            ContactNumber++;
        }
        else if (Input == "SEARCH")
        {
            if (ContactNumber > 8)
            ContactNumber = 8;
            if (Index == 0)
            {
                std::cout << "Error: Phonebook is empty." << std::endl;
                continue;
            }
            i = -1;
            std::cout << "*********************************************" << std::endl;
            std::cout << "*     INDEX│FIRST NAME│ LAST NAME│  NICKNAME*" << std::endl;
            while (++i < ContactNumber)
                Phone.displayPhoneInfo(i + 1, Phone.GetContactFirstName(i), Phone.GetContactLastName(i), Phone.GetContactNickName(i));
            std::cout << "*********************************************" << std::endl;
            std::cout << "Please select an index : ";
            std::getline(std::cin, Input);
            if (!CheckString(Input, 0))
            {
                std::cout << "Error: Invalid index value." << std::endl;
                continue;
            }
            NbrSearch = std::stoi(Input);
            if (NbrSearch < 1 || NbrSearch > ContactNumber)
                std::cout << "Error: Invalid index value." << std::endl;
            else
                Phone.displayContactInfo(NbrSearch - 1);
        }
        else if (Input == "EXIT")
            exit(0);
    }

    return (0);
}

