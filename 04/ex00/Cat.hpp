#ifndef CAT
# define CAT

#include "Animal.hpp"

class   Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat &cpy);
        ~Cat();
        Cat &operator=(const Cat &cpy);
        void    makeSound()const;
};

#endif 