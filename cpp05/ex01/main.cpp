#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Valid form ===" << std::endl;
	try {
		Form f("TaxForm", 50, 25);
		std::cout << f << std::endl;

		Bureaucrat lowRank("Intern", 100);
		Bureaucrat highRank("Director", 10);
		std::cout << highRank.getName() << std::endl;

		std::cout << lowRank << std::endl;
		std::cout << highRank << std::endl;

		std::cout << "\n--- Low rank tries to sign ---" << std::endl;
		lowRank.signForm(f);
		std::cout << f << std::endl;

		std::cout << "\n--- High rank signs ---" << std::endl;
		highRank.signForm(f); 
		std::cout << f << std::endl;

		std::cout << "\n--- Already signed, sign again ---" << std::endl;
		highRank.signForm(f);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid form grade (0) ===" << std::endl;
	try {
		Form bad("BadForm", 0, 50);
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	return 0;
}
