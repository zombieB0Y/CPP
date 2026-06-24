#include "BitcoinExchange.hpp"

int main() {
	try {
		BitcoinExchange	obj;
		obj.print_obj();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}