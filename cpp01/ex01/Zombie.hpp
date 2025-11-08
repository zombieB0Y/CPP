#pragma once

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	void announce(void);
	void set_name(std::string name);
	~Zombie();
};
Zombie* zombieHorde(int N, std::string name);
void randomChump(std::string name);
Zombie *newZombie(std::string name);