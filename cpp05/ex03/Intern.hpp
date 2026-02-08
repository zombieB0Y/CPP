#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	Intern	&operator=(const Intern &copy);
	~Intern();

	AForm	*makeForm(std::string name, std::string target);
};

AForm	*creat_shrub(std::string target);
AForm	*creat_robot(std::string target);
AForm	*creat_pardon(std::string target);