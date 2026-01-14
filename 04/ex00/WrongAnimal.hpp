#ifndef WRONG_ANIMAL
# define WRONG_ANIMAL

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(const WrongAnimal &cpy);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &cpy);
		std::string getType()const;
		void makeSound()const;
};

#endif