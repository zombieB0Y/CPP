#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	(void)ac;
	try {
		BitcoinExchange	obj;
		obj.calcule_PNL(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	// std::ifstream	file(*av);
}