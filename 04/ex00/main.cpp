#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal("kill");
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << meta->getType() << " ";
    meta->makeSound();
    std::cout << cat->getType() << " ";
    cat->makeSound();
    std::cout << dog->getType() << " ";
    dog->makeSound();
    meta->makeSound();
    delete(cat);
    delete(dog);
    delete(meta);
    // Dog d;
    // Animal *a = &d;
    // std::cout << a->getType() << " says ";
    // a->makeSound();
    //////////////////////////////////////////////////////
    WrongAnimal *wrong = new WrongCat();
    std::cout << wrong->getType() << " says ";
    wrong->makeSound();
    delete (wrong);
    return 0;
}