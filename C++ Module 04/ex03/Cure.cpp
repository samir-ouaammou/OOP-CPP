#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria("cure")
{
    _type = "cure";
    // std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure    &Cure::operator=(Cure const &src)
{
    if (this != &src)
        _type = src.getType();
    // std::cout << "Cure assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria    *Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" <<std::endl;
}
