#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// #define N_ANIMALS 10

int main()
{
    std::cout << "=== TEST 1: Array of Animals ===" << std::endl;
    const Animal* animals[10];
    std::cout << "\n[Creating Animals...]" << std::endl;
    for (int i = 0; i < 10 / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = 10 / 2; i < 10; i++) {
        animals[i] = new Cat();
    }
    std::cout << "\n[Deleting Animals...]" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }
    std::cout << "\n=== TEST 2: Deep Copy Check (Copy Constructor) ===" << std::endl;
    {
        Dog original;

        Dog copy = original; 
    } 
    std::cout << ">> If you see this message, the Copy Constructor is safe! <<" << std::endl;
    std::cout << "\n=== TEST 3: Deep Copy Check (Assignment Operator) ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        cat2 = cat1;
    }
    std::cout << ">> If you see this message, the Assignment Operator is safe! <<" << std::endl;

    return 0;
}