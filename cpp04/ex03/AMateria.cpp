#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
}

AMateria	&AMateria::operator=(const AMateria &copy) {
	(void)copy;
	return *this;
}

AMateria::~AMateria() {}


const std::string	&AMateria::getType() const {
	return this->type;
}

AMateria::AMateria(const std::string &_type) : type(_type) {}

void	AMateria::use(ICharacter &target) {
	(void)target;
}