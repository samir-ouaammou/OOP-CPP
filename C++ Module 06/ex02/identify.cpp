#include <cstdlib>
#include <ctime>
#include <iostream>
#include "identify.hpp"

Base    *generate(void)
{
    std::srand(std::time(0));
    int tmp = std::rand() % 3;

    if (tmp == 0)
        return (new A);
    
    else if (tmp == 1)
        return (new B);
    
    return (new C);
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;

    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;

    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    if (A* a = dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;

    else if (B* b = dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;

    else if (C* c = dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
}
