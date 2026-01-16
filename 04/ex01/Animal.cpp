    #include "Animal.hpp"


Animal::Animal() : type("")
{
     std::cout << "Default Animal constructor called\n";
}

Animal::Animal(std::string t) : type(t)
{
     std::cout << "Animal constructor called\n";
}


Animal::Animal(const Animal &cpy)
{
    type = cpy.type ;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &cpy)
{
    if (this != &cpy)
        type = cpy.type ;
    std::cout << "Animal assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called\n";
}

void    Animal::makeSound()const
{
    std::cout << "Animal sound!\n";
}

std::string Animal::getType()const
{
    return (type);
}