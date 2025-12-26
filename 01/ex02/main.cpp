
#include <iostream>
#include <string>

typedef std::string str;

int	main() {
	str	string = "HI THIS IS BRAIN";
	str	*stringPTR = &string;
	str	&stringREF = string;

	std::cout << "string's adress : " << &string << std::endl;
	std::cout << "string's ptr adress : " << stringPTR << std::endl;
	std::cout << "string's ref adress : " << &stringREF << std::endl;

	std::cout << "string's value : " << string << std::endl;
	std::cout << "string's ptr value : " << *stringPTR << std::endl;
	std::cout << "string's ref value : " << stringREF << std::endl;
}