#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap dt("Samir");

    std::cout << "\n=== Testing actions ===" << std::endl;
    dt.attack("target_1");         //  ScavTrap
    dt.takeDamage(20);             //  ClapTrap
    dt.beRepaired(10);             //  ClapTrap
    dt.guardGate();                //  ScavTrap
    dt.highFivesGuys();            //  FragTrap
    dt.whoAmI();                   //  DiamondTrap

    std::cout << "\n=== Destructor will be called automatically ===" << std::endl;
    return 0;
}
