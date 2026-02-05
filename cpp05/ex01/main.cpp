#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// ANSI Color Codes for readability
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"

void printHeader(const std::string& title) {
    std::cout << "\n" << BOLD << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

int main() {
    // -------------------------------------------------------------------------
    // TEST 1: Form Construction (Exceptions)
    // -------------------------------------------------------------------------
    printHeader("TEST 1: Form Construction Validation");

    try {
        std::cout << "Attempting to create invalid Form (Grade 0)..." << std::endl;
        Form invalid("TooHigh", 0, 50); // Should Throw
        std::cout << RED << "FAIL: Created Grade 0 Form!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Caught expected exception: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << "Attempting to create invalid Form (Grade 151)..." << std::endl;
        Form invalid("TooLow", 151, 50); // Should Throw
        std::cout << RED << "FAIL: Created Grade 151 Form!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Caught expected exception: " << e.what() << RESET << std::endl;
    }
    
    // Check execution grade validation as well
    try {
        std::cout << "Attempting to create invalid Execution Grade (151)..." << std::endl;
        Form invalid("ExecLow", 50, 151); // Should Throw
        std::cout << RED << "FAIL: Created Form with bad Exec Grade!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "SUCCESS: Caught expected exception: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 2: Getters and Operator<<
    // -------------------------------------------------------------------------
    printHeader("TEST 2: Display Info (operator<<)");

    try {
        Form taxForm("Tax Return", 50, 100);
        std::cout << "Created Form: Tax Return (Sign: 50, Exec: 100)" << std::endl;
        std::cout << YELLOW << "Output from << operator:\n" << RESET << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 3: Signing Process (Manual beSigned)
    // -------------------------------------------------------------------------
    printHeader("TEST 3: Manual Signing (beSigned)");

    try {
        Bureaucrat alice("Alice", 40); // High Grade
        Bureaucrat bob("Bob", 60);     // Low Grade
        Form contract("Contract", 50, 100); // Requires 50 to sign

        // 1. Fail Case
        std::cout << "Bob (Grade 60) tries to sign Contract (Req 50)..." << std::endl;
        try {
            contract.beSigned(bob);
            std::cout << RED << "FAIL: Bob signed it but shouldn't have!" << RESET << std::endl;
        } catch (Form::GradeTooLowException &e) {
            std::cout << GREEN << "SUCCESS: Bob failed to sign (" << e.what() << ")" << RESET << std::endl;
        }

        // 2. Success Case
        std::cout << "Alice (Grade 40) tries to sign Contract (Req 50)..." << std::endl;
        contract.beSigned(alice);
        std::cout << GREEN << "SUCCESS: Alice signed the contract." << RESET << std::endl;
        
        // Verify state
        std::cout << "Form State: " << contract << std::endl;

    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Crash: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 4: Bureaucrat::signForm() (The Requirements)
    // -------------------------------------------------------------------------
    printHeader("TEST 4: Bureaucrat::signForm()");

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form topSecret("Top Secret", 10, 10);

        // 1. Intern fails
        std::cout << "[Attempt 1] Intern tries to sign Top Secret:" << std::endl;
        intern.signForm(topSecret); // Should print "Intern couldn't sign... because..."

        std::cout << "\n[Attempt 2] Boss tries to sign Top Secret:" << std::endl;
        boss.signForm(topSecret);   // Should print "Boss signed Top Secret"

        std::cout << "\n[Attempt 3] Boss tries to sign AGAIN (Already signed):" << std::endl;
        boss.signForm(topSecret);   // Behavior depends on implementation, usually "signed" again or no-op
        
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Crash: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 5: Boundary Checks
    // -------------------------------------------------------------------------
    printHeader("TEST 5: Boundary Conditions (Grade == Req)");

    try {
        Bureaucrat exact("Exacto", 50);
        Form boundary("BoundaryForm", 50, 50); // Requires exactly 50

        std::cout << "Bureaucrat Grade 50 signing Form Req 50:" << std::endl;
        exact.signForm(boundary); // Should SUCCEED (>= logic)
        
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected Crash: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    return 0;
}