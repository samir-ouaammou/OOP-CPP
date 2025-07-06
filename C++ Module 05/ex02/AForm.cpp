#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm    &AForm::operator=(const AForm &src)
{
    if (this != &src)
        _isSigned = src._isSigned;

    return (*this);
}

AForm::~AForm()
{
}

const std::string   &AForm::getName() const
{
    return (_name);
}

bool    AForm::isSigned() const
{
    return (_isSigned);
}

int     AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int     AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void    AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade too high!");
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too low!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm " << form.getName()
        << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
