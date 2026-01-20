#include "Animal.hpp"


// ****************************************************



Animal::Animal() : type("Animal") {
	print_msg("Animal constructor called !");
}

Animal::Animal(const Animal &copy) {
	print_msg("animal copy constructor called !");
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
	// print_msg("animal operator '=' is called !");
	if (this != &copy)
		type = copy.getType();
	return *this;
}

Animal::~Animal() {
	print_msg("animal destructor is called !");
}



// ****************************************************



void	Animal::makeSound() const {
	print_msg("Animal sound....");
}

std::string	Animal::getType(void) const {
	return (type);
}

void	print_msg(std::string msg) {
	std::cout << msg << std::endl;
}