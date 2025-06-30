#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
}

Cure    &Cure::operator=(Cure const &src)
{
    if (this != &src)
        _type = src.getType();
    return (*this);
}

Cure::~Cure()
{
}

AMateria    *Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
