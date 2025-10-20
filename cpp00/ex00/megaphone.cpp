#include <iostream>

std::string	mega(char *s)
{
	std::string meg = s;
	for (unsigned long i = 0; i < meg.length(); i++)
		meg[i] = std::toupper(static_cast<unsigned char>(meg[i]));
	return meg;
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
		{
			std::string s = mega(av[i]);
			std::cout << s;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
