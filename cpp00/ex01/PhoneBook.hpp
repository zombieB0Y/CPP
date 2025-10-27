#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int	size;

public:
	void ADD(void);
	void SEARCH(void);
	void EXIT(void);
	PhoneBook();
};