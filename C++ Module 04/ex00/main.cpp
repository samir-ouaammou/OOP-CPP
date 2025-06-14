#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << ">>> Test 1: Animal hierarchy with virtual functions\n" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n>>> Animal types\n" << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n>>> Animal sounds\n" << std::endl;
    animal->makeSound();  // Generic
    dog->makeSound();     // Dog sound
    cat->makeSound();     // Cat sound

    std::cout << "\n>>> Deleting animals\n" << std::endl;
    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n>>> Test 2: WrongAnimal without virtual\n" << std::endl;

    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << "\n>>> WrongAnimal types\n" << std::endl;
    std::cout << "WrongAnimal type: " << wronganimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongcat->getType() << std::endl;

    std::cout << "\n>>> WrongAnimal sounds\n" << std::endl;
    wronganimal->makeSound();  // Generic wrong sound
    wrongcat->makeSound();     // Still wrong sound (no polymorphism)

    std::cout << "\n>>> Deleting wrong animals\n" << std::endl;
    delete wronganimal;
    delete wrongcat;

    return (0);
}
