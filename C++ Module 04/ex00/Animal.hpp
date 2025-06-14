# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal  &operator=(const Animal &src);
        virtual ~Animal();

        std::string     getType(void) const;
        void            setType(const std::string type);

        virtual void    makeSound(void) const;
};

# endif
