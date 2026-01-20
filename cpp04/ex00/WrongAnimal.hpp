#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	virtual ~WrongAnimal();

	void makeSound(void) const;
	std::string getType(void) const;
};
