#include "Cat.hpp"

// ****************************************************

Cat::Cat() : Animal() {
	print_msg("Cat constructor called !");
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	print_msg("Cat copy constructor called !");
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Cat::~Cat() {
	print_msg("Cat destructor is called !");
}


// ****************************************************



void	Cat::makeSound(void) const {
	print_msg("Cat : meow...!");
}