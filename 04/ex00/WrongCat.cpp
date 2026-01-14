#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& cpy)
{
    if (this != &cpy)
        WrongAnimal::operator=(cpy);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}
void    WrongCat::makeSound()const
{
    std::cout << "Meooww!" << std::endl;
}