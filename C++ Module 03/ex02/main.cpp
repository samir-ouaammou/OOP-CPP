#include "FragTrap.hpp"

int main()
{
    std::cout << "Creating FragTrap...\n";
    FragTrap frag("Optimus");

    std::cout << "\n--- Attack test ---\n";
    frag.attack("Megatron");

    std::cout << "\n--- Damage test ---\n";
    frag.takeDamage(40);

    std::cout << "\n--- Repair test ---\n";
    frag.beRepaired(25);

    std::cout << "\n--- High Fives test ---\n";
    frag.highFivesGuys();

    std::cout << "\n--- Energy drain test ---\n";
    for (int i = 0; i < 101; ++i) {
        frag.attack("Training Bot");
    }

    std::cout << "\n--- Post-energy repair test ---\n";
    frag.beRepaired(10);

    std::cout << "\nEnd of test.\n";

    return 0;
}
