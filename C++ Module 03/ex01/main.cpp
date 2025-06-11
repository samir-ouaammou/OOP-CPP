#include "ScavTrap.hpp"

int main()
{
    std::cout << "Creating ScavTrap...\n";
    ScavTrap scav("Guardian");

    std::cout << "\nTesting attack:\n";
    scav.attack("Intruder");

    std::cout << "\nTesting takeDamage:\n";
    scav.takeDamage(30);

    std::cout << "\nTesting beRepaired:\n";
    scav.beRepaired(20);

    std::cout << "\nTesting guardGate:\n";
    scav.guardGate();

    std::cout << "\nDraining energy:\n";
    for (int i = 0; i < 51; ++i) {
        scav.attack("Dummy");
    }

    std::cout << "\nTesting after energy drained:\n";
    scav.beRepaired(10);

    std::cout << "\nEnd of main.\n";
    return 0;
}
