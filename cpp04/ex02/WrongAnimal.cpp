#include "WrongAnimal.hpp"
#include "AAnimal.hpp"


// ****************************************************



WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	print_msg("WrongAnimal constructor called !");
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	print_msg("WrongAnimal copy constructor called !");
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	// print_msg("WrongAnimal operator '=' is called !");
	if (this != &copy)
		type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() {
	print_msg("WrongAnimal destructor is called !");
}



// ****************************************************



void	WrongAnimal::makeSound() const {
	print_msg("WrongAnimal sound....");
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}