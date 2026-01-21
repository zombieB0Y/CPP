#pragma once

#include "AAnimal.hpp"

class Dog : public AAnimal
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