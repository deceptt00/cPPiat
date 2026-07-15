#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern  intern;
	Bureaucrat boss("Boss", 1);

	std::cout << "=== Intern creates shrubbery creation ===" << std::endl;
	{
		AForm *f = NULL;
		try {
			f = intern.makeForm("shrubbery creation", "garden");
			boss.signForm(*f);
			boss.executeForm(*f);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete f;
	}

	std::cout << "\n=== Intern creates robotomy request ===" << std::endl;
	{
		AForm *f = NULL;
		try {
			f = intern.makeForm("robotomy request", "Bender");
			boss.signForm(*f);
			boss.executeForm(*f);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete f;
	}

	std::cout << "\n=== Intern creates presidential pardon ===" << std::endl;
	{
		AForm *f = NULL;
		try {
			f = intern.makeForm("presidential pardon", "Marvin");
			boss.signForm(*f);
			boss.executeForm(*f);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete f;
	}

	std::cout << "\n=== Intern tries unknown form ===" << std::endl;
	{
		AForm *f = NULL;
		try {
			f = intern.makeForm("coffee form", "someone");
		} catch (std::exception &e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		delete f;
	}

	return 0;
}
