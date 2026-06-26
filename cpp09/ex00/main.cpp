#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "need input file.\n";
		return 1;
	}
	try {
		BitcoinExchange	obj;
		obj.calcule_PNL(av[1]);
	}
	catch (std::exception &e) {}
}