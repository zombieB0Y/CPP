#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp" 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
    std::cout << BLUE << "=== SETUP ===" << RESET << std::endl;
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1);
    
    AForm* rrf = NULL; 

    std::cout << "\n" << BLUE << "=== TEST 1: ROBOTOMY REQUEST ===" << RESET << std::endl;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf != NULL) {
        std::cout << GREEN << "Success: Form created at address " << rrf << RESET << std::endl;
        
        boss.signForm(*rrf);
        boss.executeForm(*rrf);

        delete rrf; 
        rrf = NULL;
    } else {
        std::cout << RED << "Fail: Form was not created!" << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 2: SHRUBBERY CREATION ===" << RESET << std::endl;

    rrf = someRandomIntern.makeForm("shrubbery creation", "Home");

    if (rrf != NULL) {
        std::cout << GREEN << "Success: Form created." << RESET << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        rrf = NULL;
    } else {
        std::cout << RED << "Fail: Form was not created!" << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 3: PRESIDENTIAL PARDON ===" << RESET << std::endl;

    rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    if (rrf != NULL) {
        std::cout << GREEN << "Success: Form created." << RESET << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        rrf = NULL;
    } else {
        std::cout << RED << "Fail: Form was not created!" << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 4: UNKNOWN FORM (FAILURE TEST) ===" << RESET << std::endl;

    rrf = someRandomIntern.makeForm("coffee request", "Office");

    if (rrf == NULL) {
        std::cout << GREEN << "Success: Intern correctly returned NULL for unknown form." << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL: Intern created a form for unknown input!" << RESET << std::endl;
        delete rrf;
    }

    return 0;
}