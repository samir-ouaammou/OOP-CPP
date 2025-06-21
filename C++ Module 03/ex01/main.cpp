#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "----- Creating ClapTrap -----" << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\n----- Creating ScavTrap -----" << std::endl;
    ScavTrap scav("Scavvy");

    std::cout << "\n----- Testing attack() -----" << std::endl;
    clap.attack("target1");
    scav.attack("target2");

    std::cout << "\n----- Testing takeDamage() -----" << std::endl;
    scav.takeDamage(30);

    std::cout << "\n----- Testing beRepaired() -----" << std::endl;
    scav.beRepaired(20);

    std::cout << "\n----- Testing ScavTrap special ability -----" << std::endl;
    scav.guardGate();

    std::cout << "\n----- End of main, destructors will be called -----" << std::endl;
    return 0;
}
