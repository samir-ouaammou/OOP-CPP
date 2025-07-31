# include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    if (this != &copy)
        *this = copy;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src)
    {
        for (short i = 0; i < 100; i++)
            this->_ideas[i] = src._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
