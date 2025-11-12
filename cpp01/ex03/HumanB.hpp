#pragma once

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon*      weapon;
    public:
        void    attack();
        void    setWeapon(Weapon& _weapon);
        HumanB(std::string _name);
};