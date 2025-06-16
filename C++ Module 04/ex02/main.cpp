# include "AbstractAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

int main()
{
    const AbstractAnimal* j = new Dog();
    const AbstractAnimal* i = new Cat();

    delete j;
    delete i;

    return (0);
}
