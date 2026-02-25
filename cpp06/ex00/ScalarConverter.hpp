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
