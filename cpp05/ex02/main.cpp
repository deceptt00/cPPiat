#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 140);

	std::cout << boss << std::endl;
	std::cout << worker << std::endl << std::endl;

	// ── ShrubberyCreationForm (sign 145, exec 137) ─────────────────────────
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	{
		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;
		worker.signForm(shrubbery);   // grade 140 <= 145 → OK
		worker.executeForm(shrubbery); // grade 140 > 137 → FAIL
		boss.executeForm(shrubbery);   // grade 1 <= 137 → OK
	}

	// ── RobotomyRequestForm (sign 72, exec 45) ─────────────────────────────
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	{
		RobotomyRequestForm robo("Bender");
		std::cout << robo << std::endl;
		worker.signForm(robo);   // grade 140 > 72 → FAIL
		boss.signForm(robo);     // grade 1 <= 72 → OK
		boss.executeForm(robo);
		boss.executeForm(robo);  // 50% chance each time
	}

	// ── PresidentialPardonForm (sign 25, exec 5) ───────────────────────────
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	{
		PresidentialPardonForm pardon("Marvin");
		std::cout << pardon << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}

	// ── Execute unsigned form ───────────────────────────────────────────────
	std::cout << "\n=== Execute unsigned form ===" << std::endl;
	{
		PresidentialPardonForm unsigned_form("Ghost");
		boss.executeForm(unsigned_form);
	}

	return 0;
}
