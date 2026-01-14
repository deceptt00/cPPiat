#ifndef ANIMAL
# define ANIMAL
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string t);
		Animal(const Animal &cpy);
		virtual ~Animal();
		Animal &operator=(const Animal &cpy);
		std::string getType()const;
		virtual void makeSound()const = 0;
};

#endif