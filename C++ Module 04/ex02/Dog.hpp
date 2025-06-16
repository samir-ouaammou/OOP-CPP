# ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AbstractAnimal.hpp"
# include "Brain.hpp"

class Dog : public AbstractAnimal
{
    private:
        Brain   *_brain;

    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &src);
        ~Dog();

        void    makeSound(void) const;
};

# endif
