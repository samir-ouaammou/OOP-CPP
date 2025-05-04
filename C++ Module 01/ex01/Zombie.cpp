#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

std::string Zombie::getName(void)
{
    return (_name);
}

void    Zombie::setName(std::string newName)
{
    _name = newName;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


