#pragma once
#include "Contact.hpp"
class PhoneBook
{
private:
	Contact contacts[8];
public:
	void ADD(Contact a);
	void SEARCH(void);
	void EXIT(void);
};