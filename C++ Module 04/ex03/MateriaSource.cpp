#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;

    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = NULL;
            }

            if (src._materias[i])
                _materias[i] = src._materias[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            // std::cout << "Learned new materia in slot " << i << std::endl;
            return;
        }
    }

    // std::cout << "MateriaSource is full! Cannot learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            // std::cout << "Created a copy of materia: " << type << std::endl;
            return _materias[i]->clone();
        }
    }

    // std::cout << "Materia of type '" << type << "' not found!" << std::endl;
    return NULL;
}
