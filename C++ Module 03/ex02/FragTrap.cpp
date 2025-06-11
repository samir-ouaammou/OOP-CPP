#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created (default)" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    if (this != &other)
        *this = other;
    std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void    FragTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no energy or is already dead and can't attack!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " powerfully attacks " << target << ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests high fives from everyone!" << std::endl;
}