#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& cpy)
{
    if (this != &cpy)
        Animal::operator=(cpy);
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called\n";
}
void    Cat::makeSound()const
{
    std::cout << "Meooww!" << std::endl;
}