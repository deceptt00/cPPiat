#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	// std::cout << "=== Valid bureaucrats ===" << std::endl;
	// try {
	// 	Bureaucrat alice("Alice", 1);
	// 	Bureaucrat bob("Bob", 75);
	// 	Bureaucrat charlie("Charlie", 150);
	// 	std::cout << alice << std::endl;
	// 	std::cout << bob << std::endl;
	// 	std::cout << charlie << std::endl;

	// 	std::cout << "\n=== Increment/Decrement ===" << std::endl;
	// 	bob.incrementGrade();
	// 	std::cout << bob << " (after increment)" << std::endl;
	// 	bob.decrementGrade();
	// 	bob.decrementGrade();
	// 	std::cout << bob << " (after 2x decrement)" << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }

	std::cout << "\n=== Grade too high (0) ===" << std::endl;
	// try {
		Bureaucrat invalid("TooHigh", 0);
	// } catch (std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// std::cout << "\n=== Grade too low (151) ===" << std::endl;
	// try {
	// 	Bureaucrat invalid("TooLow", 151);
	// } catch (std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// std::cout << "\n=== Increment past grade 1 ===" << std::endl;
	// try {
	// 	Bureaucrat top("Top", 1);
	// 	top.incrementGrade();
	// } catch (std::exception &e) {
	// 	std::cerr << "Caught: " << e.what() << std::endl;
	// }

	// std::cout << "\n=== Decrement past grade 150 ===" << std::endl;
	// try {
	// 	Bureaucrat bottom("Bottom", 150);
	// 	bottom.decrementGrade();
	// } catch (...) {
	// 	std::cerr << "Caught: " << "int error " << std::endl;
	// }

	return 0;
}
