#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap serena("Serena");
    FragTrap original("Original");


    serena.attack("Target Dummy");
    serena = original;

    serena.takeDamage(10);
    // serena.beRepaired(5);
    // serena.highFivesGuys();
    // std::cout << "\n----------------------------------------\n" << std::endl;
    // FragTrap copyCat(original);
    // copyCat.highFivesGuys();
    // std::cout << "\n----------------------------------------\n" << std::endl;
    // ClapTrap test("zoubair");

    // test.beRepaired(100);
    return 0;
}