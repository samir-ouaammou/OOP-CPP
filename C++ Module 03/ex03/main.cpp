#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap dt("Samir");

    std::cout << "\n=== Testing actions ===" << std::endl;
    dt.attack("target_1");         // من ScavTrap
    dt.takeDamage(20);             // من ClapTrap
    dt.beRepaired(10);             // من ClapTrap
    dt.guardGate();                // من ScavTrap
    dt.highFivesGuys();            // من FragTrap
    dt.whoAmI();                   // خاص بـ DiamondTrap

    std::cout << "\n=== Destructor will be called automatically ===" << std::endl;
    return 0;
}
