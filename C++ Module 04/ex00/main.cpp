#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "---------------constructor---------------" << std::endl;
    const Animal* i = new Cat();
    const WrongAnimal* j = new WrongCat();
    std::cout << "\n---------------getType---------------" << std::endl;
    
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "\n---------------makeSound---------------" << std::endl;
    
    i->makeSound();
    j->makeSound();
    std::cout << "\n---------------Destructor---------------" << std::endl;

    delete i;
    delete j;

    return 0;
}
