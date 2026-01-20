#include "Dog.hpp"

// ****************************************************

Dog::Dog() : Animal() {
	print_msg("Dog constructor called !");
	type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	print_msg("Dog copy constructor called !");
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Dog::~Dog() {
	print_msg("Dog destructor is called !");
}


// ****************************************************



void	Dog::makeSound(void) const {
	print_msg("Dog : WOOF...!");
}