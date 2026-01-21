#include "Cat.hpp"

// ****************************************************

Cat::Cat() : Animal() {
	print_msg("Cat constructor called !");
	brain = new Brain;
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	print_msg("Cat copy constructor called !");
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	print_msg("Cat destructor is called !");
}


// ****************************************************



void	Cat::makeSound(void) const {
	print_msg("Cat : meow...!");
}