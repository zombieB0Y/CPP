#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Subject Tests ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "Type: " << j->getType() << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    std::cout << "\n=== Wrong Animal Tests ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound();
    wrongMeta->makeSound();
    delete wrongCat;
    delete wrongMeta;    
    return 0;
}