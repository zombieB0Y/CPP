#pragma once

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter	&operator=(const ScalarConverter &copy);
	~ScalarConverter();
public:
	static void	convert(const std::string &s);
};


bool	check_for_numbers(const std::string &s);

void	print_character(int c);
void	print_non_printable(int c);
void	print_error(std::string msg);