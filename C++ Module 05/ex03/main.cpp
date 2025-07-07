#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("RobotomyRequestForm", "Garden");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("ShrubberyCreationForm", "Samir");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return (0);
}
