#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot("CLAPPY");
	std::cout << "\n--- TESTING ENERGY DRAIN ---" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		robot.attack("Target_Dummy");
	}

	std::cout << "\n--- TESTING HEALING CAP ---" << std::endl;
	ClapTrap healer("MEDIC");
	healer.takeDamage(5);
	healer.beRepaired(1);
	healer.beRepaired(100);

	std::cout << "\n--- TESTING DEATH ---" << std::endl;
	healer.takeDamage(20);
	healer.attack("Zombie");
	healer.beRepaired(10);

	return 0;
}