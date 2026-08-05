#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high (min is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low (max is 150)";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << "here" << std::endl;
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << f.getName()
		          << " because " << e.what() << std::endl;
	}
}
