# include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()
{
    _type = "AbstractAnimal";
    std::cout << "AbstractAnimal Default constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(std::string type)
{
    _type = type;
    std::cout << "AbstractAnimal constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &copy)
{
    if (this != &copy)
        *this = copy;
    std::cout << "AbstractAnimal Copy constructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &src)
{
    if (this != &src)
        _type = src._type;
    std::cout << "AbstractAnimal Copy assignment operator called" << std::endl;
    return (*this);
}

AbstractAnimal::~AbstractAnimal()
{
    std::cout << "AbstractAnimal Destructor called" << std::endl;
}

std::string AbstractAnimal::getType(void) const
{
    return (_type);
}

void    AbstractAnimal::setType(const std::string type)
{
    _type = type;
}
