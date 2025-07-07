#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm   &operator=(const AForm &src);
        virtual ~AForm();

        const std::string   &getName() const;
        bool    isSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;

        void    beSigned(const Bureaucrat &b);

        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class NotSignedException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, const AForm &form);

#endif
