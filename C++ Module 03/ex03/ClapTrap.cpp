#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "Default_clap_name";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " created (default)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)    
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    if (this != &other)
        *this = other;
    std::cout << "ClapTrap " << _name << " copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy or is already dead and can't attack!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints <= 0)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and died!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage, remaining HP: " << _hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy or is already dead and can't repair!" << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points! HP is now " << _hitPoints << std::endl;
}
