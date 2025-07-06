#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    // Try to sign and execute ShrubberyCreationForm
    std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
    worker.signForm(shrub);      // should succeed
    worker.executeForm(shrub);   // should fail (grade too low)
    boss.executeForm(shrub);     // should succeed

    // Try to sign and execute RobotomyRequestForm
    std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
    boss.signForm(robot);        // should succeed
    boss.executeForm(robot);     // should succeed

    // Try to sign and execute PresidentialPardonForm
    std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
    boss.signForm(pardon);       // should succeed
    boss.executeForm(pardon);    // should succeed

    return 0;
}