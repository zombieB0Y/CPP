#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	void	beSigned(Bureaucrat &officer);
	void	creatForm(std::string target);
};
