#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    AForm* form;

    std::cout << "\n--- Intern creates ShrubberyCreationForm ---" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form)
    {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Intern creates RobotomyRequestForm ---" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        Bureaucrat alice("Alice", 1);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Intern creates PresidentialPardonForm ---" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        Bureaucrat zaphod("Zaphod", 1);
        zaphod.signForm(*form);
        zaphod.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Intern tries to create UnknownForm ---" << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return 0;
}
