# ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

# include <iostream>

class AbstractAnimal
{
    protected:
        std::string _type;

    public:
        AbstractAnimal();
        AbstractAnimal(std::string type);
        AbstractAnimal(const AbstractAnimal &copy);
        AbstractAnimal  &operator=(const AbstractAnimal &src);
        virtual ~AbstractAnimal();

        std::string     getType(void) const;
        void            setType(const std::string type);

        virtual void    makeSound(void) const = 0;
};

# endif
