#include "Zombie.hpp"

Zombie*	NewZombie(std::string name) {
	Zombie* _newzombie = new Zombie(name);
	return _newzombie;
}