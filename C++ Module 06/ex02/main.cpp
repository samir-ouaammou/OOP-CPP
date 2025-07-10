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

    // //--------------------------
    // Base* b = new A();

    // A* d = dynamic_cast<A*>(b);
    // if (!d)
    //     std::cout << "Cast failed\n";

    // delete b;

    // // //--------------------------
    // Base* b = new Base();

    // A* d = dynamic_cast<A*>(b);
    // if (!d)
    //     std::cout << "Cast failed\n";

    // delete b;

    return 0;
}