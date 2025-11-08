#include "Zombie.hpp"

int main() {
    Zombie* horde = zombieHorde(5, "zoubair");
    if (!horde)
        return 1;
    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }
    delete[] horde;
}