#include <iostream>
#include "identify.hpp"

int main()
{
    Base *ptr = generate();

    std::cout << "Identify by pointer: ";
    identify(ptr);

    std::cout << "Identify by reference: ";
    identify(*ptr);

    delete ptr;

    return 0;
}