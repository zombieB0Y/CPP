#include "WrongCat.hpp"
#include "AAnimal.hpp"

// ****************************************************

WrongCat::WrongCat() : WrongAnimal() {
	print_msg("WrongCat constructor called !");
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	print_msg("WrongCat copy constructor called !");
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat() {
	print_msg("WrongCat destructor is called !");
}


// ****************************************************



void	WrongCat::makeSound(void) const {
	print_msg("WrongCat : meow...!");
}