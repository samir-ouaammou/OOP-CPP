#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    // std::cout << "AMateria constructor called" << std::endl;
    _type = type;
}

AMateria::AMateria(AMateria const &copy)
{
    // std::cout << "AMateria Copy constructor called" << std::endl;
    *this = copy;
}

AMateria    &AMateria::operator=(AMateria const &src)
{
    // std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &src)
        _type = src.getType();
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
    return (_type);
}

void    AMateria::use(ICharacter& target)
{
    (void) target;
}
