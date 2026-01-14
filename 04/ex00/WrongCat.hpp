#ifndef WRONG_CAT
# define WRONG_CAT


#include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &cpy);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &cpy);
        void    makeSound()const;
};

#endif