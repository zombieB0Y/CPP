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
