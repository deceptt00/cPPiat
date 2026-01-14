#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    brain = new Brain(*cpy.brain);
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& cpy)
{
    if (this != &cpy)
    {
        Animal::operator=(cpy);
        delete brain ;
        brain = new Brain(*cpy.brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}
void    Cat::makeSound()const
{
    std::cout << "Meooww!" << std::endl;
}