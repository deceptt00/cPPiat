#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
    brain = new Brain(*cpy.brain);
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& cpy)
{
    if (this != &cpy)
    {
        Animal::operator=(cpy);
        delete brain ;
        brain = new Brain(*cpy.brain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}
void    Dog::makeSound()const
{
    std::cout << "Woof!" << std::endl;
}