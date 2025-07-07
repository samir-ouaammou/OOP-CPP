#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}

Intern::~Intern()
{
}

AForm   *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *form = NULL;

    if (formName == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else if (formName == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (formName == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else
    {
        std::cerr << "Intern can't create form: " << formName << std::endl;
        return (NULL);
    }

    std::cout << "Intern creates " << formName << std::endl;
    return (form);
}
