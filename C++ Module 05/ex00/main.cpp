#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Create a valid Bureaucrat with grade 5
        Bureaucrat b1("Samir", 5);
        std::cout << b1 << std::endl;

        // Increment the grade (should become 4)
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        // Decrement the grade (should go back to 5)
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        // Try to create a Bureaucrat with invalid grade (too low)
        Bureaucrat b2("BadBureaucrat", 151);
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception while creating b2: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        // Create a Bureaucrat with grade 1 (highest possible)
        Bureaucrat b3("TopRank", 1);
        std::cout << b3 << std::endl;

        // Try to increment the grade (should throw an exception)
        b3.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception while incrementing b3: " << e.what() << std::endl;
    }

    return 0;
}
