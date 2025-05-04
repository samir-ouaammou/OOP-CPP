#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    Zombie  *horde;
    short   Number;

    Number = 5;
    horde = zombieHorde(Number, "1337");

    for (short i = 0; i < Number; i++)
        horde[i].announce();

    delete[] horde;

    return (0);
}
