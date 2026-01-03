#pragma once

#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int HP;
	unsigned int ENG;
	unsigned int ATT;
	unsigned int max_hp;

public:
	// OCF
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	virtual ~ClapTrap();

	ClapTrap(std::string _name);
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string GetName(void) const;
	unsigned int GetHP(void) const;
	unsigned int GetATT(void) const;
	unsigned int GetENG(void) const;
	unsigned int Getmax_hp(void) const;
};
