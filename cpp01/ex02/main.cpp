#include <string>
#include <iostream>

int main() {
	std::string		line = "HI THIS IS BRAIN";
	std::string*	stringPTR = &line;
	std::string&	stringREF = line;

	std::cout << &line << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << line << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}