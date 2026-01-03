#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap DEFAULT CONSTUCTOR CALLED !" << std::endl;
	this->HP = 100;
	this->ENG = 50;
	this->ATT = 20;
	this->max_hp = 100;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap PARAMETERIZED CONSTUCTOR CALLED !" << std::endl;
	this->HP = 100;
	this->ENG = 50;
	this->ATT = 20;
	this->max_hp = 100;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap COPY CONSTUCTOR CALLED !" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap OPERATOR '=' CALLED !" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap DESTRUCTOR CALLED !" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->HP > 0 && this->ENG > 0)
	{
		this->ENG--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << ATT << " points of damage!" << std::endl;
	}
	else if (this->HP == 0)
		std::cout << "ScavTrap " << name << " cannot attack cuz he is FR DEAD!" << std::endl;
	else if (this->ENG == 0)
		std::cout << "ScavTrap " << name << " is out of ENERGY !" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->HP > 0)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap " << name << " is DEAD CANT GATE KEEP !" << std::endl;
}
