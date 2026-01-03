#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "STACK ALLOCATION" << std::endl;
    {
        ScavTrap serena("Serena");
        serena.attack("Target Dummy");
        serena.takeDamage(10);
        serena.beRepaired(5);
        serena.guardGate();
    }
    std::cout << "\n----------------------------------------\n" << std::endl;
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    {
        ScavTrap original("Original");
        ScavTrap copyCat(original);
        copyCat.guardGate();
    }
    std::cout << "\n----------------------------------------" << std::endl;

    return 0;
}