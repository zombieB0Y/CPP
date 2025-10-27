#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	size = 0;
}

void PhoneBook::ADD(void) {
	if (size == 8)
	{
		size = 0;
		contacts[size].set_first_name(std::cout << "enter first name" >> std::cin)
	}
}
