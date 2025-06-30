#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    _type = type;
}

AMateria::AMateria(AMateria const &copy)
{
    *this = copy;
}

AMateria    &AMateria::operator=(AMateria const &src)
{
    if (this != &src)
        _type = src.getType();
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return (_type);
}

void    AMateria::use(ICharacter& target)
{
    (void) target;
}
