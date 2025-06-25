#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name)
{
    // std::cout << "Character constructor called" << std::endl;

    _name = name;
    _tmpIndex = 0;

    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;

    for (int i = 0; i < 1000; i++)
        _tmp[i] = NULL;
}

Character::Character(Character const &copy)
{
    // std::cout << "Character Copy constructor called" << std::endl;

    _name = copy._name;
    _tmpIndex = 0;

    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }

    for (int i = 0; i < 1000; i++)
        _tmp[i] = NULL;
}

Character &Character::operator=(Character const &src)
{
    // std::cout << "Character Copy assignment operator called" << std::endl;

    if (this != &src)
    {
        _name = src._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (src._inventory[i])
                _inventory[i] = src._inventory[i]->clone();
        }
        for (int i = 0; i < 1000; i++)
        {
            if (_tmp[i])
            {
                delete _tmp[i];
                _tmp[i] = NULL;
            }
        }
        _tmpIndex = 0;
    }
    return (*this);
}

Character::~Character()
{
    // std::cout << "Character Destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (_tmp[i])
        {
            delete _tmp[i];
            _tmp[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;

    if (_tmpIndex < 1000)
        _tmp[_tmpIndex++] = _inventory[idx];

    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;

    _inventory[idx]->use(target);
}
