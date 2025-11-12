#include "Replacer.hpp"


void	error_msg(std::string msg) {
	std::cerr << msg;
}

int	main(int ac, char **av) {
	if (ac != 4) {
		error_msg("Argument Error\n");
		return 1;
	}
	Replacer starter(av[1], av[2], av[3]);
	if (!starter.replace()) {
		error_msg("failed replace\n");
		return 1;
	}


}