#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "need an argument!\n";
		return 1;
	}
	RPN obj(av[1]);
	return 0;
}