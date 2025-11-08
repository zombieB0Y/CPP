#include "Zombie.hpp"

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
    std::cout << name << ": NnnnuuuuUgh... B-B-Br... (Gurgle)... Zzz...\n";
}

void    Zombie::set_name(std::string name) {
    this->name = name;
}