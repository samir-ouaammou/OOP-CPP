# ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AbstractAnimal.hpp"
# include "Brain.hpp"

class Cat : public AbstractAnimal
{
    private:
        Brain   *_brain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &src);
        ~Cat();

        void    makeSound(void) const;
};

# endif
