#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

Form::~Form() {}

const std::string  Form::getName()          const { return _name; }
bool               Form::isSigned()         const { return _signed; }
int                Form::getGradeToSign()   const { return _gradeToSign; }
int                Form::getGradeToExecute()const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: grade is too high (min is 1)";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form: grade is too low, cannot sign";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form [" << f.getName() << "]"
	    << " | signed: " << (f.isSigned() ? "yes" : "no")
	    << " | grade to sign: " << f.getGradeToSign()
	    << " | grade to execute: " << f.getGradeToExecute();
	return out;
}
