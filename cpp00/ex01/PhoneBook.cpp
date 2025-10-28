#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	size = 0;
}

void PhoneBook::ADD(void)
{
	if (size == 8)
	{
		size = 0;
		std::string line;
		std::cout << "enter first name :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_first_name(line);
		std::cout << "enter last name :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_last_name(line);
		std::cout << "enter nickname :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_nickname(line);
		std::cout << "enter phone number :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_phone_number(line);
		std::cout << "enter darkest secret :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_darkest_secret(line);
	}
	else
	{
		std::string line;
		std::cout << "enter first name :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_first_name(line);
		std::cout << "enter last name :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_last_name(line);
		std::cout << "enter nickname :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_nickname(line);
		std::cout << "enter phone number :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_phone_number(line);
		std::cout << "enter darkest secret :" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		contacts[size].set_darkest_secret(line);
		size++;
	}
}

void	PhoneBook::SEARCH(void)
{
	
}