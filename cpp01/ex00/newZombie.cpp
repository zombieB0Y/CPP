#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie* _newzombie = new Zombie(name);
	return _newzombie;
}