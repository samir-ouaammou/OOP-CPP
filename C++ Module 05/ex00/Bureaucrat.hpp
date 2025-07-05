#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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

        const std::string &getName() const;
        int getGrade() const;

        void    incrementGrade();
        void    decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
