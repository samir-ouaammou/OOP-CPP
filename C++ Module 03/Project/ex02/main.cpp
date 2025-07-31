#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "----- Creating ClapTrap -----" << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\n----- Creating ScavTrap -----" << std::endl;
    ScavTrap scav("Scavvy");

    std::cout << "\n----- Creating FragTrap -----" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n----- Testing attacks -----" << std::endl;
    clap.attack("target1");
    scav.attack("target2");
    frag.attack("target3");

    std::cout << "\n----- Testing takeDamage() -----" << std::endl;
    frag.takeDamage(40);

    std::cout << "\n----- Testing beRepaired() -----" << std::endl;
    frag.beRepaired(25);

    std::cout << "\n----- Testing FragTrap special ability -----" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n----- End of main, destructors will be called -----" << std::endl;
    return 0;
}
