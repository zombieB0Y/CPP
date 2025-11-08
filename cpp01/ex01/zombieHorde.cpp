#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N > 0) {
        Zombie* _new = new Zombie[N];
        for (int i = 0; i < N; i++) {
            _new[i].set_name(name);
        }
        return _new;
    }
    else
        return NULL;
}