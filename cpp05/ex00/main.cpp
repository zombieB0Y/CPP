#include <iostream>
#include "Bureaucrat.hpp"

int main() {

    std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        bob.inc_grade();
        std::cout << bob << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        bob.dec_grade();
        std::cout << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Constructor Too High (Grade 0) ---" << std::endl;
    try {
        Bureaucrat superman("Superman", 0);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Constructor Too Low (Grade 151) ---" << std::endl;
    try {
        Bureaucrat lazy("Lazy", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Increment beyond 1 ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.inc_grade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrement beyond 150 ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.dec_grade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}