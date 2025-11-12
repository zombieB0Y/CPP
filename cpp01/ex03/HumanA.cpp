#include "HumanA.hpp"
#include "Weapon.hpp"

void    HumanA::attack() {
    
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string _name ,Weapon& _weapon)  : weapon(_weapon){
    name = _name;
}