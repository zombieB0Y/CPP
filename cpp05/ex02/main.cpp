#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printTitle(std::string title) {
    std::cout << "\n" << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

int main()
{
    printTitle("TEST 1: Shrubbery Creation (File I/O)");
    try {
        Bureaucrat bob("Bob", 140);
        Bureaucrat mike("Mike", 130);
        ShrubberyCreationForm shrub("Garden");

        std::cout << "1. Bob tries to execute unsigned form:" << std::endl;
        bob.executeForm(shrub);

        std::cout << "\n2. Bob signs the form:" << std::endl;
        bob.signForm(shrub);

        std::cout << "\n3. Bob tries to execute signed form (Grade too low):" << std::endl;
        bob.executeForm(shrub);
        std::cout << "\n4. Mike executes the form:" << std::endl;
        mike.executeForm(shrub);
        
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printTitle("TEST 2: Robotomy Request (50% Chance)");
    try {
        Bureaucrat boss("Boss", 40);
        RobotomyRequestForm robot("Bender");

        boss.signForm(robot);

        std::cout << "Running Robotomy 4 times to test randomness:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << YELLOW << "[Attempt " << i + 1 << "] " << RESET;
            boss.executeForm(robot);
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printTitle("TEST 3: Presidential Pardon (High Level)");
    try {
        Bureaucrat prez("Zaphod", 5); 
        Bureaucrat vp("Vice Prez", 20);
        PresidentialPardonForm pardon("Arthur Dent");

        vp.signForm(pardon);
        
        std::cout << "VP tries to execute:" << std::endl;
        vp.executeForm(pardon);

        std::cout << "\nPresident tries to execute:" << std::endl;
        prez.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printTitle("TEST 4: Deep Copy & Abstract Class");

    // AForm test("Abstract", 1, 1); 

    try {
        ShrubberyCreationForm original("Original");
        Bureaucrat signer("Signer", 1);
        signer.signForm(original);

        std::cout << "Original status: " << original << std::endl;

        ShrubberyCreationForm copy(original);
        std::cout << "Copy status:     " << copy << std::endl;
        
        std::cout << GREEN << "Success: Deep copy preserved signed status!" << RESET << std::endl;

    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
	printTitle("TEST 5: EDGE CASES & STRESS TEST");

    std::cout << "\n--- [Edge Case 1: Unsigned Execution] ---" << std::endl;
    try {
        Bureaucrat cheater("Cheater", 1);
        RobotomyRequestForm robot("Target");

        robot.execute(cheater); 
        std::cout << RED << "FAIL: Unsigned form was executed!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Caught exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}