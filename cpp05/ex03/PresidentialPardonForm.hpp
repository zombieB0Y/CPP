#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string _name);

	void	exe() const;
};