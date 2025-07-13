#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "---- Test 1: Empty array ----" << std::endl;
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        std::cout << "\n---- Test 2: Array with 5 elements ----" << std::endl;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); ++i)
            b[i] = (i + 1) * 10;

        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        std::cout << "\n---- Test 3: Copy constructor ----" << std::endl;
        Array<int> c(b);
        c[0] = 999;
        std::cout << "b[0] = " << b[0] << std::endl;
        std::cout << "c[0] = " << c[0] << std::endl;

        std::cout << "\n---- Test 4: Assignment operator ----" << std::endl;
        Array<int> d;
        d = c;
        d[1] = 777;
        std::cout << "c[1] = " << c[1] << std::endl;
        std::cout << "d[1] = " << d[1] << std::endl;

        std::cout << "\n---- Test 5: Const access ----" << std::endl;
        const Array<int> e(d);
        std::cout << "e[2] = " << e[2] << std::endl;

        std::cout << "\n---- Test 6: Out of bounds ----" << std::endl;
        std::cout << "e[100] = " << e[100] << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
