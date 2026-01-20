#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &copy);
	~Dog();


	void	makeSound(void) const;
};