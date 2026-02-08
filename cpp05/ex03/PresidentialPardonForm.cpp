#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy){
		AForm::operator=(copy);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//*---------------------------------------------------------------------------------------*

PresidentialPardonForm::PresidentialPardonForm(std::string _name) : AForm(_name, 25, 5) {}

void	PresidentialPardonForm::exe() const {
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}