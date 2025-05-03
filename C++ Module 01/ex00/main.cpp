#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "=== Random Chump (stack) ===" << std::endl;
    randomChump("stack");

    std::cout << "\n=== New Zombie (heap) ===" << std::endl;
    Zombie* heapZombie = newZombie("heap");
    heapZombie->announce();

    delete heapZombie;

    return (0);
}
