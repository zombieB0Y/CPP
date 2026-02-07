#pragma once
#include "AForm.hpp"
#include <fstream>
// #include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string _name);

	void	exe() const;
};