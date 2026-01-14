#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("")
{
     std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string t = "undefined") : type(t)
{
     std::cout << "WrongAnimal constructor called\n";
}


WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
    type = cpy.type ;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy)
{
    if (this != &cpy)
        type = cpy.type ;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called\n";
}

void    WrongAnimal::makeSound()const
{
    std::cout << "WrongAnimal sound!\n";
}

std::string WrongAnimal::getType()const
{
    return (type);
}