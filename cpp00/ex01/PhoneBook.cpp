#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	offset = 0;
}

bool is_all_whitespace(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!isspace(str[i]))
			return false;
	}
	return true;
}

std::string	trim(std::string& input) {
	std::string::size_type start = input.find_first_not_of(" \t\n\r\v\f");
	std::string::size_type end = input.find_last_not_of(" \t\n\r\v\f");
	return input.substr(start, end - start + 1);
}

bool	parse_phone(std::string& phone) {
	for (size_t i = 0; i < phone.size(); i++) {
		if (!isdigit(phone[i]))
			return false;
	}
	return true;
}

void	parse_input(std::string& input, const std::string& msg) {
	for ( ; ; ) {
		if (input.empty() || is_all_whitespace(input))
		{
			std::cout << msg;
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl;
				return;
			}
			continue;
		}
		break;
	}
}

void	parse_phonenumber(std::string& input) {
	for ( ; ; ) {
		if (!parse_phone(input))
		{
			std::cout << "enter phone number :";
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl;
				return;
			}
			continue;
		}
		break;
	}
}

void PhoneBook::ADD(void)
{
	if (size == 8)
	{
		if (offset == 8)
			offset = 0;
		std::string line;
		std::cout << "enter first name :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter first name :");
		line = trim(line);
		contacts[offset].set_first_name(line);
		std::cout << "enter last name :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter last name :");
		line = trim(line);
		contacts[offset].set_last_name(line);
		std::cout << "enter nickname :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter nickname :");
		line = trim(line);
		contacts[offset].set_nickname(line);
		std::cout << "enter phone number :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter phone number :");
		line = trim(line);
		contacts[offset].set_phone_number(line);
		std::cout << "enter darkest secret :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter darkest secret :");
		line = trim(line);
		contacts[offset].set_darkest_secret(line);
		offset++;
	}
	else
	{
		std::string line;
		std::cout << "enter first name :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter first name :");
		line = trim(line);
		contacts[size].set_first_name(line);
		std::cout << "enter last name :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter last name :");
		line = trim(line);
		contacts[size].set_last_name(line);
		std::cout << "enter nickname :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter nickname :");
		line = trim(line);
		contacts[size].set_nickname(line);
		std::cout << "enter phone number :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter phone number :");
		line = trim(line);
		parse_phonenumber(line);
		contacts[size].set_phone_number(line);
		std::cout << "enter darkest secret :";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return;
		}
		parse_input(line, "enter darkest secret :");
		line = trim(line);
		contacts[size].set_darkest_secret(line);
		size++;
	}
}

bool	parse_index(std::string& input, int& index)	{
	if (input.empty())
		return false;
	for	(size_t i = 0; i < input.size(); i++) {
		if (!std::isdigit(input[i]))
			return false;
	}
	index = std::atoi(input.c_str());
	return true;
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
	for ( ; ; ) {
		std::cout << "Enter the index of the contact to display: ";
		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return;
		}
		if (parse_index(input, index))
			break ;
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