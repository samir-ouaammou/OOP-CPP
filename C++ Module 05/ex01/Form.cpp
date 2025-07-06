#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form    &Form::operator=(const Form &src)
{
    if (this != &src)
        _isSigned = src._isSigned;

    return (*this);
}

Form::~Form()
{
}

const std::string   &Form::getName() const
{
    return (_name);
}

bool    Form::isSigned() const
{
    return (_isSigned);
}

int     Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int     Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void    Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high!");
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName()
        << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
