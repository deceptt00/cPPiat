#ifndef DOG
# define DOG

#include "Animal.hpp"

class   Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog &cpy);
        ~Dog();
        Dog &operator=(const Dog &cpy);
        void    makeSound()const;
};

#endif