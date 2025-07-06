#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Samir", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b2("Samir", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
