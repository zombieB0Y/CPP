#include "HumanB.hpp"

HumanB::HumanB(std::string _name) {
    name = _name;
    weapon->setType(NULL);
}

void    HumanB::attack() {
    if (weapon->getType())
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon _weapon) {
    *weapon = _weapon;
}