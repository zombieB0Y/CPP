#pragma once

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    std::string getType();
    void        setType(std::string _type);
    Weapon(std::string _weapon);
};