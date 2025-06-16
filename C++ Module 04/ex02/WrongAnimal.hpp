# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &src);
        ~WrongAnimal();

        std::string getType(void) const;
        void        setType(const std::string type);

        void        makeSound(void) const;
};

# endif
