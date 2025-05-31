# include "Harl.hpp"
# include <iostream>

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n"; 
    std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]\n"; 
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]\n"; 
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]\n"; 
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    Harl    harl;
    int     levelIndex = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex)
    {
        case 0:
            harl.debug();

        case 1:
            harl.info();

        case 2:
            harl.warning();

        case 3:
            harl.error();
            break;
            
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
