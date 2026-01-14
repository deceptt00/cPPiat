#ifndef CAT
# define CAT

#include "Animal.hpp"
#include "Brain.hpp"
class   Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &cpy);
        ~Cat();
        Cat &operator=(const Cat &cpy);
        void    makeSound()const;
};

#endif