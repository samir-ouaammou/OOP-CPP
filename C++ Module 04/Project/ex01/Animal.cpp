# include "Animal.hpp"

Animal::Animal()
{
    _type = "Animal";
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    _type = type;
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    if (this != &copy)
        *this = copy;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    if (this != &src)
        _type = src._type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}

void    Animal::setType(const std::string type)
{
    _type = type;
}
void    Animal::makeSound(void) const
{
    std::cout << "Animal Sound" << std::endl;
}
