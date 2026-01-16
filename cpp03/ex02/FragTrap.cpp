#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap DEFAULT CONSTUCTOR CALLED !" << std::endl;
	this->HP = 100;
	this->ENG = 100;
	this->ATT = 30;
	this->max_hp = 100;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "FragTrap PARAMETERIZED CONSTUCTOR CALLED !" << std::endl;
	this->HP = 100;
	this->ENG = 100;
	this->ATT = 30;
	this->max_hp = 100;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap COPY CONSTUCTOR CALLED !" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap OPERATOR '=' CALLED !" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap DESTRUCTOR CALLED !" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->HP > 0 && this->ENG > 0)
	{
		this->ENG--;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << ATT << " points of damage!" << std::endl;
	}
	else if (this->HP == 0)
		std::cout << "FragTrap " << name << " cannot attack cuz he is FR DEAD!" << std::endl;
	else if (this->ENG == 0)
		std::cout << "FragTrap " << name << " is out of ENERGY !" << std::endl;
}
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " high five ajamii" << std::endl;
}
