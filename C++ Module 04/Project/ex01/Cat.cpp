# include "Cat.hpp"

Cat::Cat() : Animal()
{
    _brain = new Brain();
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    _brain = new Brain(*copy._brain);
    if (this != &copy)
        *this = copy;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        *_brain = *src._brain;
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat Sound" << std::endl;
}
