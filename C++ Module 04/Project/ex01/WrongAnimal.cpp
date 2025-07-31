# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "WrongAnimal";
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    if (this != &copy)
        *this = copy;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src)
        _type = src._type;
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}

void    WrongAnimal::setType(const std::string type)
{
    _type = type;
}
void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}
