#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("RobotA");
    ClapTrap b("RobotB");

    std::cout << std::endl;

    a.attack("RobotB");
    b.takeDamage(0);

    std::cout << std::endl;

    b.beRepaired(5);

    std::cout << std::endl;

    for (int i = 1; i < 10; ++i)
        a.attack("RobotB"); 

    std::cout << std::endl;

    a.beRepaired(3);

    std::cout << std::endl;

    return 0;
}
