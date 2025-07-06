#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        const std::string &getName(void) const;
        int getGrade(void) const;

        void    incrementGrade(void);
        void    decrementGrade(void);

        void    signForm(AForm &form);

        void    executeForm(AForm const &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
