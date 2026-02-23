#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Please provide exactly one argument." << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);

    return 0;
}