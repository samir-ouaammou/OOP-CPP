#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("robotomy request", "Garden");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("shrubbery creation", "Samir");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return (0);
}
