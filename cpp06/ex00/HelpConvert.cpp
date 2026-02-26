#include "HelpConvert.hpp"

HelpConvert::HelpConvert() {}
HelpConvert::HelpConvert(const HelpConvert& other) { *this = other; }
HelpConvert& HelpConvert::operator=(const HelpConvert& other) { 
	(void)other; 
	return *this; 
}
HelpConvert::~HelpConvert() {}

HelpConvert::ConversionError::ConversionError(const std::string& msg) throw() : _msg(msg) {}
HelpConvert::ConversionError::~ConversionError() throw() {}
const char* HelpConvert::ConversionError::what() const throw() {
	return _msg.c_str();
}

//*------------------------------------------------------------------------*//

void HelpConvert::printConversionResult(char c, const std::string& type) {
	std::cout << type << ": ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void HelpConvert::printConversionResult(int i, const std::string& type) {
	std::cout << type << ": " << i << std::endl;
}

void HelpConvert::printConversionResult(float f, const std::string& type) {
	std::cout << type << ": " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void HelpConvert::printConversionResult(double d, const std::string& type) {
	std::cout << type << ": " << std::fixed << std::setprecision(1) << d << std::endl;
}

void HelpConvert::printConversionResult(const std::string& val, const std::string& type) {
	std::cout << type << ": " << val << std::endl;
}

//*-------------------------------------------------------------------------------------------------*//

void HelpConvert::isChar(const std::string &s) {
	if (s.length() != 1 || std::isdigit(s[0])) {
		throw ConversionError("Not a valid character");
	}
	char c = s[0];
	
	printConversionResult(c, "char");
	printConversionResult(static_cast<int>(c), "int");
	printConversionResult(static_cast<float>(c), "float");
	printConversionResult(static_cast<double>(c), "double");
}

void HelpConvert::isInt(const std::string &s) { // atoi() chab3ana protoein
	long long val = 0;
	int sign = 1;
	size_t i = 0;

	if (s[i] == '+' || s[i] == '-') {
		if (s[i] == '-')
			sign = -1;
		i++;
	}

	if (i == s.length()) throw ConversionError("Not a valid integer");

	for (; i < s.length(); ++i) {
		if (!std::isdigit(s[i])) throw ConversionError("Not a valid integer");
		val = val * 10 + (s[i] - '0');
		
		if (val * sign > std::numeric_limits<int>::max() || val * sign < std::numeric_limits<int>::min()) {
			throw ConversionError("Integer overflow");
		}
	}

	int final_int = static_cast<int>(val * sign);
	if (final_int >= std::numeric_limits<char>::min() && final_int <= std::numeric_limits<char>::max())
		printConversionResult(static_cast<char>(final_int), "char");
	else
		printConversionResult("impossible", "char");

	printConversionResult(final_int, "int");
	printConversionResult(static_cast<float>(final_int), "float");
	printConversionResult(static_cast<double>(final_int), "double");
}

void HelpConvert::isFloat(const std::string &s) {
	char* endptr;
	errno = 0;
	
	float f = std::strtof(s.c_str(), &endptr);

	if (errno == ERANGE) throw ConversionError("Float overflow/underflow");
	if (*endptr != 'f' || *(endptr + 1) != '\0') throw ConversionError("Not a valid float");

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
		printConversionResult(static_cast<char>(f), "char");
	else
		printConversionResult("impossible", "char");

	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		printConversionResult(static_cast<int>(f), "int");
	else
		printConversionResult("impossible", "int");

	printConversionResult(f, "float");
	printConversionResult(static_cast<double>(f), "double");
}

void HelpConvert::isDouble(const std::string &s) {
	char* endptr;
	errno = 0;
	
	double d = std::strtod(s.c_str(), &endptr);

	if (errno == ERANGE) 
    {
		printConversionResult("impossible", "char");
		printConversionResult("impossible", "int");
		printConversionResult(static_cast<float>(d), "float");
	    printConversionResult(d, "double");
        return;
    }
	if (*endptr != '\0') throw ConversionError("Not a valid double");

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
		printConversionResult(static_cast<char>(d), "char");
	else
		printConversionResult("impossible", "char");

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		printConversionResult(static_cast<int>(d), "int");
	else
		printConversionResult("impossible", "int");
	printConversionResult(static_cast<float>(d), "float");
	printConversionResult(d, "double");
	// std::cout << std::numeric_limits<double>::max() << std::endl;
    
}

void HelpConvert::isPseudoLiteral(const std::string &s) {
	std::string float_pseudos[] = {"-inff", "+inff", "nanf"};
	std::string double_pseudos[] = {"-inf", "+inf", "nan"};
	
	bool is_float = false;
	bool is_double = false;
	int index = -1;

	for (int i = 0; i < 3; ++i) {
		if (s == float_pseudos[i]) {
			is_float = true;
			index = i;
			break;
		}
		if (s == double_pseudos[i]) {
			is_double = true;
			index = i;
			break;
		}
	}

	if (!is_float && !is_double) {
		throw ConversionError("Not a valid pseudo-literal");
	}

	printConversionResult("impossible", "char");
	printConversionResult("impossible", "int");
	printConversionResult(float_pseudos[index], "float");
	printConversionResult(double_pseudos[index], "double");
}