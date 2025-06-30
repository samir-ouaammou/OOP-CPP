#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

// int main()
// {
//     std::cout << "=== Creating Materia Source ===\n";
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     std::cout << "\n=== Creating Character ===\n";
//     ICharacter* me = new Character("Samir");

//     std::cout << "\n=== Equipping 5 Materias (slot should only take 4) ===\n";
//     AMateria* m1 = src->createMateria("ice");
//     AMateria* m2 = src->createMateria("cure");
//     AMateria* m3 = src->createMateria("ice");
//     AMateria* m4 = src->createMateria("cure");
//     AMateria* m5 = src->createMateria("ice"); // this one shouldn't be equipped

//     me->equip(m1); // slot 0
//     me->equip(m2); // slot 1
//     me->equip(m3); // slot 2
//     me->equip(m4); // slot 3
//     me->equip(m5); // should be ignored

//     std::cout << "\n=== Creating Bob ===\n";
//     ICharacter* bob = new Character("Bob");

//     std::cout << "\n=== Using Equipped Materias ===\n";
//     for (int i = 0; i < 4; ++i)
//         me->use(i, *bob);

//     std::cout << "\n=== Testing unequip on slot 1 and 2 ===\n";
//     me->unequip(1); // Cure
//     me->unequip(2); // Ice

//     std::cout << "\n=== Trying to use unequipped slots (should do nothing) ===\n";
//     me->use(1, *bob);
//     me->use(2, *bob);

//     std::cout << "\n=== Cleaning up ===\n";
//     delete bob;
//     delete me;
//     delete src;

//     delete m5;

//     return 0;
// }