#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	// OCF
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	~FragTrap();

	FragTrap(std::string _name);
	void attack(const std::string &target);
    void highFivesGuys(void);
};
