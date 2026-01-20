#pragma once
#include "Animal.hpp"
#include <iostream>

class Brain
{    
public:
    Brain();
    Brain(const Brain &copy);
    Brain   &operator=(const Brain &copy);
    ~Brain();

    std::string ideas[100];
};
