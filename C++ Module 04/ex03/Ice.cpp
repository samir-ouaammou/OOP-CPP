#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice() : AMateria("ice")
{
    _type = "ice";
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &src)
{
    if (this != &src)
        _type = src.getType();
    // std::cout << "Ice assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria    *Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
