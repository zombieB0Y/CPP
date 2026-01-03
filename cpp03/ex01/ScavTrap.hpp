#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// OCF
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap(std::string _name);
	void attack(const std::string &target);
	void guardGate();
};
