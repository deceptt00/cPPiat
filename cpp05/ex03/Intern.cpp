#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

// ─── Static factories ─────────────────────────────────────────────────────────

AForm *Intern::makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

// ─── makeForm — function pointer dispatch table ───────────────────────────────

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	// Table of form names and their factory functions — no if/else chain
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static const FormFactory factories[3] = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePardon
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			AForm *form = factories[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw UnknownFormException();
}

// ─── Exception ───────────────────────────────────────────────────────────────

const char *Intern::UnknownFormException::what() const throw()
{
	return "Intern: unknown form name";
}
