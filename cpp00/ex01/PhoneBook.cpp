#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

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

void PhoneBook::SEARCH(void)
{
	int index;
    if (size == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].get_first_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_last_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_nickname()) << std::endl;
    }
    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    if (!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return;
    }
    try {
        index = std::stoi(input); // c++11 not c++98 tfo
    } catch (...)
	{
        std::cout << "Invalid index." << std::endl;
        return;
    }
    if (index < 0 || index >= size)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

std::string PhoneBook::truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}