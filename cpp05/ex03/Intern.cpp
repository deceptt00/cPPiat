#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm *makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *makePardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*forms[3])(const std::string&) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePardon
    };

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			AForm *form = forms[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw FormNotFound();
}

const char *Intern::FormNotFound::what() const throw()
{
	return "Intern: unknown form name";
}
