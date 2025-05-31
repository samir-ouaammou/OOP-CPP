# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <iostream>
# include <algorithm>

short   CheckString(const std::string& str, short nbr)
{
    unsigned long   i;

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
        if (str.empty())
            exit(0);
        if (!CheckString(str, nbr))
            continue;
        else
            break; ;
    }
}

int main(void)
{
    std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret, Input;
    short       Index, i, NbrSearch, ContactNumber;
    PhoneBook   Phone;

    Index = 0;
    ContactNumber = 0;
    while (1)
    {
        std::cout << "Please enter a command. (ADD, SEARCH OR EXIT): ";
        std::getline(std::cin, Input);
        if (Input.empty())
            exit(0);
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
            if (Input.empty())
                exit(0);
            if (!CheckString(Input, 0))
            {
                std::cout << "Error: Invalid index value." << std::endl;
                continue;
            }
            NbrSearch = std::atoi(Input.c_str());
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
