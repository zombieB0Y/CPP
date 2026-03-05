#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Function prototypes
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    std::cout << "--- Testing Random Generation ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* randomObj = generate();
        std::cout << "Test index: " << i << std::endl;
        
        std::cout << "Pointer identify: ";
        identify(randomObj);
        
        std::cout << "Reference identify: ";
        identify(*randomObj);
        
        delete randomObj;
        std::cout << std::endl;
    }

    std::cout << "--- Testing Explicit Types ---" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "Explicit A pointer: ";
    identify(a);
    std::cout << "Explicit A reference: ";
    identify(*a);

    std::cout << "Explicit B pointer: ";
    identify(b);
    std::cout << "Explicit B reference: ";
    identify(*b);

    std::cout << "Explicit C pointer: ";
    identify(c);
    std::cout << "Explicit C reference: ";
    identify(*c);

    delete a;
    delete b;
    delete c;

    std::cout << "\n--- Testing Null Pointer Edge Case ---" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Null pointer identify: ";
    identify(nullPtr);

    return 0;
}