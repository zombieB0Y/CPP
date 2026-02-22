#include "ScalarConverter.hpp"


void	print_character(int c) {
	std::cout << "char: '" << static_cast<char>(c) << "'\n";
	std::cout << "int: " << c << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	print_non_printable(int c) {
	std::cout << "char: " << "Non displayable" << "\n";
	std::cout << "int: " << c << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	print_error(std::string msg) {
	std::cerr << msg << std::endl;
}

int	main(int ac, char **av) {
	if (ac == 2) {
		char *end;
		double	arg = strtod(av[1], &end);
		if (av[1][0] == 0)
			print_error("empty !");
		else if (av[1] == end) {
			std::string	arg(av[1]);
			if (arg.length() > 1)
				print_error("not valid !");
			else if (isprint(av[1][0]))
				print_character(av[1][0]);
		}
		else if (errno == ERANGE)
			print_error("too big \"that what she said ;)\" !");
		else {
			if (arg < 127 && isprint(arg))
				print_character(arg);
			else
				print_non_printable(arg);
		}
	}
	else
		return 1;
}