#include "AAnimal.hpp"


// ****************************************************



AAnimal::AAnimal() : type("Animal") {
	print_msg("Animal constructor called !");
}

AAnimal::AAnimal(const AAnimal &copy) {
	print_msg("animal copy constructor called !");
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	// print_msg("animal operator '=' is called !");
	if (this != &copy)
		type = copy.getType();
	return *this;
}

AAnimal::~AAnimal() {
	print_msg("animal destructor is called !");
}



// ****************************************************

std::string	AAnimal::getType(void) const {
	return (type);
}

void	print_msg(std::string msg) {
	std::cout << msg << std::endl;
}