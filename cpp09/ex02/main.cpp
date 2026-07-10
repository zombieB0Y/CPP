#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integer> [positive integer ...]" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeMe;
		pmergeMe.parseArguments(argc, argv);
		pmergeMe.execute();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}