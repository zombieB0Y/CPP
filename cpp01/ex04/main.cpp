#include "Replacer.hpp"


int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Argument Error\n";
		return 1;
	}
	Replacer starter(av[1], av[2], av[3]);
	if (!starter.replace()) {
		starter.error_msg("failed replace\n");
		return 1;
	}
}