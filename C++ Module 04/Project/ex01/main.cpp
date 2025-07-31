#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    return (0);
}

// int main()
// {
//     const int SIZE = 100;
//     Animal* animals[SIZE];

//     std::cout << "\n🔹 Creating 50 Dogs and 50 Cats:\n";
//     for (int i = 0; i < SIZE / 2; ++i)
//         animals[i] = new Dog();

//     for (int i = SIZE / 2; i < SIZE; ++i)
//         animals[i] = new Cat();

//     std::cout << "\n🔹 Playing sounds:\n";
//     for (int i = 0; i < SIZE; ++i)
//         animals[i]->makeSound();

//     std::cout << "\n🔹 Deleting all animals:\n";
//     for (int i = 0; i < SIZE; ++i)
//         delete animals[i];

//     return 0;
// }