#pragma once
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>

class PhoneBook
{
private:
	Contact contacts[8];
	int	size;
	int	offset;

public:
	void ADD(void);
	void SEARCH(void);
	std::string truncate(std::string str);
	PhoneBook();
};