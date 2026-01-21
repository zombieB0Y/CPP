#pragma once

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &copy);
	~Cat();


	void	makeSound(void) const;
};