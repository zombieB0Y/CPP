#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy){
		AForm::operator=(copy);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//*---------------------------------------------------------------------------------------*

RobotomyRequestForm::RobotomyRequestForm(std::string _name) : AForm(_name, 72, 45) {}

void	RobotomyRequestForm::exe() const {
	std::cout << "ZZZZT! ZZRRRRT!..." << std::endl;
	std::ifstream urandom("/dev/urandom");

    if (urandom.is_open()) {
        char ch = 0;
		urandom.read(&ch, 1);
        urandom.close();

        if (ch % 2 == 0) {
            std::cout << this->getName() << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy failed for " << this->getName() << "." << std::endl;
        }
    } else {
        std::cout << "Robotomy failed (System Error)." << std::endl;
    }
}