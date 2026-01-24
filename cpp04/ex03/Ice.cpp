#include "Ice.hpp"

//*******************************************************************************

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy) {};

Ice	&Ice::operator=(const Ice &copy) {
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}

Ice::~Ice() {}

//*********************************************************************************

AMateria	*Ice::clone() const{
	Ice *_new = new Ice(*this);
	return _new;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}