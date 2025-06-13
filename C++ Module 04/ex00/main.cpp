#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << ">>> Test 1: Real polymorphism with virtual\n";
    const Animal* meta = new Animal(); // optional, if Animal not abstract yet
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " => ";
    j->makeSound(); // should print "Woof!"
    
    std::cout << i->getType() << " => ";
    i->makeSound(); // should print "Meow!"

    std::cout << "meta (Animal) => ";
    meta->makeSound(); // should print generic Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n>>> Test 2: WrongAnimal without virtual\n";

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << " => ";
    wrongAnimal->makeSound(); // should print "WrongAnimal sound"

    std::cout << wrongCat->getType() << " => ";
    wrongCat->makeSound(); // ❌ will print "WrongAnimal sound" (wrong!)

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
