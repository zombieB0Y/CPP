#pragma once

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &copy);
	virtual ~AAnimal();

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

void print_msg(std::string msg);