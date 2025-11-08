#include "Zombie.hpp"

int main() {
    Zombie* _new = newZombie("zoubair");
    _new->announce();
    randomChump("anas");
    delete _new;
}