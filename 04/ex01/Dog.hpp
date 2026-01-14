#ifndef DOG
# define DOG

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &cpy);
        ~Dog();
        Dog &operator=(const Dog &cpy);
        void    makeSound()const;
};

#endif