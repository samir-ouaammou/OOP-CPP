# include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    _type = type;
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    if (this != &copy)
        *this = copy;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        Animal::operator=(src);
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat Sound" << std::endl;
}
