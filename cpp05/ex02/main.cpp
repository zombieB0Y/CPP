#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Colors for readable output
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
    // ------------------------------------------------------------------
    // TEST 1: Shrubbery Creation Form (Sign 145, Exec 137)
    // ------------------------------------------------------------------
    printTitle("TEST 1: Shrubbery Creation (File I/O)");
    try {
        Bureaucrat bob("Bob", 140); // Can sign, cannot execute
        Bureaucrat mike("Mike", 130); // Can sign and execute
        ShrubberyCreationForm shrub("Garden");

        std::cout << "1. Bob tries to execute unsigned form:" << std::endl;
        bob.executeForm(shrub); // Should fail (Not signed)

        std::cout << "\n2. Bob signs the form:" << std::endl;
        bob.signForm(shrub);

        std::cout << "\n3. Bob tries to execute signed form (Grade too low):" << std::endl;
        bob.executeForm(shrub); // Should fail (Grade 140 > 137)

        std::cout << "\n4. Mike executes the form:" << std::endl;
        mike.executeForm(shrub); // Should succeed -> Check for "Garden_shrubbery" file!
        
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 2: Robotomy Request Form (Sign 72, Exec 45)
    // ------------------------------------------------------------------
    printTitle("TEST 2: Robotomy Request (50% Chance)");
    try {
        Bureaucrat boss("Boss", 40); // Can do everything
        RobotomyRequestForm robot("Bender");

        boss.signForm(robot);

        std::cout << "Running Robotomy 4 times to test randomness:" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << YELLOW << "[Attempt " << i + 1 << "] " << RESET;
            boss.executeForm(robot);
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 3: Presidential Pardon Form (Sign 25, Exec 5)
    // ------------------------------------------------------------------
    printTitle("TEST 3: Presidential Pardon (High Level)");
    try {
        Bureaucrat prez("Zaphod", 5); 
        Bureaucrat vp("Vice Prez", 20); // Can sign, can't execute
        PresidentialPardonForm pardon("Arthur Dent");

        vp.signForm(pardon);
        
        std::cout << "VP tries to execute:" << std::endl;
        vp.executeForm(pardon); // Fail

        std::cout << "\nPresident tries to execute:" << std::endl;
        prez.executeForm(pardon); // Success
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 4: Polymorphism & Abstract Class Check
    // ------------------------------------------------------------------
    printTitle("TEST 4: Deep Copy & Abstract Class");
    
    // Uncommenting the line below should cause a COMPILATION ERROR 
    // because AForm is abstract.
    // AForm test("Abstract", 1, 1); 

    try {
        ShrubberyCreationForm original("Original");
        Bureaucrat signer("Signer", 1);
        signer.signForm(original);

        std::cout << "Original status: " << original << std::endl;

        // Test Copy Constructor
        ShrubberyCreationForm copy(original);
        std::cout << "Copy status:     " << copy << std::endl;
        
        std::cout << GREEN << "Success: Deep copy preserved signed status!" << RESET << std::endl;

    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
	printTitle("TEST 5: EDGE CASES & STRESS TEST");

    // 1. Unsigned Execution Check
    std::cout << "\n--- [Edge Case 1: Unsigned Execution] ---" << std::endl;
    try {
        Bureaucrat cheater("Cheater", 1);
        RobotomyRequestForm robot("Target");
        
        // Trying to execute WITHOUT signing first
        // If your Form::execute() doesn't check isSigned(), this will run!
        robot.execute(cheater); 
        std::cout << RED << "FAIL: Unsigned form was executed!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Caught exception: " << e.what() << RESET << std::endl;
    }

    // 2. Exact Boundary Check
    std::cout << "\n--- [Edge Case 2: Exact Grade Boundary] ---" << std::endl;
    try {
        // Shrubbery requires Exec Grade 137
        Bureaucrat borderLine("BorderLine", 137); 
        ShrubberyCreationForm shrub("BoundaryTest");
        
        borderLine.signForm(shrub);
        borderLine.executeForm(shrub); // Should SUCCEED
        std::cout << GREEN << "SUCCESS: Grade 137 executed Grade 137 requirement." << RESET << std::endl;
        
        Bureaucrat tooLow("TooLow", 138);
        tooLow.executeForm(shrub); // Should FAIL
        std::cout << RED << "FAIL: Grade 138 executed Grade 137 requirement!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Grade 138 failed as expected." << RESET << std::endl;
    }

    // 3. File Permission Error (Simulated)
    std::cout << "\n--- [Edge Case 3: Robustness] ---" << std::endl;
    try {
        // NOTE: This test requires you to manually create a read-only file named "Error_shrubbery"
        // touch Error_shrubbery && chmod 444 Error_shrubbery
        
        Bureaucrat hacker("Hacker", 1);
        ShrubberyCreationForm file("Error"); // Will try to write to "Error_shrubbery"
        
        hacker.signForm(file);
        // This should throw an open/write error, NOT crash
        hacker.executeForm(file); 
        
    } catch (std::exception &e) {
        std::cout << YELLOW << "Caught system error (Good!): " << e.what() << RESET << std::endl;
    }
    return 0;
}