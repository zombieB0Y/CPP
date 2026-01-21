#include "Dog.hpp"

// ****************************************************

Dog::Dog() : Animal() {
	print_msg("Dog constructor called !");
	brain = new Brain;
	type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	print_msg("Dog copy constructor called !");
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	print_msg("Dog destructor is called !");
}


// ****************************************************



void	Dog::makeSound(void) const {
	print_msg("Dog : WOOF...!");
}