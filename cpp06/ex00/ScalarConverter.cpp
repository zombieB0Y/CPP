#include "ScalarConverter.hpp"
#include "HelpConvert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy) {
	if (this != &copy) {}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

//*----------------------------------------*


void	ScalarConverter::convert(const std::string &s) {
	try {
        HelpConvert::isPseudoLiteral(s);
        return;
    } catch (const HelpConvert::ConversionError&) {}
    try {
        HelpConvert::isChar(s);
        return;
    } catch (const HelpConvert::ConversionError&) {}
    try {
        HelpConvert::isInt(s);
        return;
    } catch (const HelpConvert::ConversionError&) {}
    try {
        HelpConvert::isFloat(s);
        return;
    } catch (const HelpConvert::ConversionError&) {}
    try {
        HelpConvert::isDouble(s);
        return;
    } catch (const HelpConvert::ConversionError&) {}
    std::cerr << "Error: Unknown literal type." << std::endl;
}

// bool	check_for_numbers(const std::string &s) {
// 	if (isInt(s)) {
// 		try {

// 		}
// 		catch (...) {

// 		}
// 	}
// 	// char		*end;
// 	// const char	*s_str = s.c_str();
// 	// double		arg = strtod(s_str, &end);
// 	// if (s_str != end && *end == 0) {
// 	// 	if (isprint(arg))
// 	// 		print_character(arg);
// 	// 	else
// 	// 		print_non_printable(arg);
// 	// }
// 	// else if (s_str == end) {
// 	// 	return false;
// 	// }
// }

// bool	isInt(const std::string &s) {
// 	size_t	i = 0;

// 	for (; i < s.length() && isspace(s[i]); i++) {}
// 	if (s[i] == '+' || s[i] == '-')
// 		i++;
// 	for (; i < s.length() && isspace(s[i]); i++) {}
// 	for (; i < s.length(); i++) {
// 		if (!isdigit(s[i]))
// 			return false;
// 	}
// 	return true;
// }

// void	print_character(int c) {
// 	std::cout << "char: '" << static_cast<char>(c) << "'\n";
// 	std::cout << "int: " << c << "\n";
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << static_cast<float>(c) << "f\n";
// 	std::cout << "double: " << static_cast<double>(c) << "\n";
// }

// void	print_non_printable(int c) {
// 	std::cout << "char: " << "Non displayable" << "\n";
// 	std::cout << "int: " << c << "\n";
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << static_cast<float>(c) << "f\n";
// 	std::cout << "double: " << static_cast<double>(c) << "\n";
// }

// void	print_error(std::string msg) {
// 	std::cerr << msg << std::endl;
// }