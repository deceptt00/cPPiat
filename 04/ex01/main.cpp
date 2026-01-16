#include "Cat.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     Animal *animals[4];

// 	animals[0] = new Dog();
// 	animals[1] = new Dog();
// 	animals[2] = new Cat();
// 	animals[3] = new Cat();

// 	for (int i = 0; i < 4; i++)
// 		delete animals[i];
//     return 0;
// }


int main()
{
	Cat *a = new Cat();
	Cat *b = new Cat();

	*b = *a;

	std::cout << b << std::endl;
	std::cout << a << std::endl;
	delete a;
	delete b;
}