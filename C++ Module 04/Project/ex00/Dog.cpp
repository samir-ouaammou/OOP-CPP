# include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    _type = type;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    if (this != &copy)
        *this = copy;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
        Animal::operator=(src);
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog Sound" << std::endl;
}
