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

static AForm	*makePresident(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}


AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string	nameForms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*(*allForms[])(const std::string&) = {&makePresident, &makeRobot, &makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (formName == nameForms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (allForms[i](target));
		}
	}
	std::cerr << "Intern can't create form: " << formName << std::endl;
	return (NULL);
}
