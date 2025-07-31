#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
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
            return ;
        }
    }

}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return (_materias[i]->clone());
        }
    }

    return (NULL);
}
