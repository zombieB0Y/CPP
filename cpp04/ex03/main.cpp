#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// ANSI Colors for readability
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printHeader(std::string title) {
    std::cout << "\n" << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

// 1. Test basic subject functionality (Baseline)
void testSubject() {
    printHeader("SUBJECT TEST");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

// 2. Test MateriaSource limits (Learning > 4 items)
// DOES IT LEAK the 5th item?
void testMateriaSourceLimits() {
    printHeader("MATERIA SOURCE LIMITS");
    IMateriaSource* src = new MateriaSource();
    
    std::cout << "Learning 4 items..." << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "Trying to learn 5th item (Should be deleted automatically)..." << std::endl;
    AMateria* extra = new Ice();
    src->learnMateria(extra); // If your logic is correct, this pointer is deleted inside
    std::cout << "Standard 5th item passed (check valgrind for leaks)." << std::endl;

    // Test creating unknown materia
    AMateria* unknown = src->createMateria("fire");
    if (unknown == 0)
        std::cout << GREEN << "Correctly returned NULL for unknown materia." << RESET << std::endl;
    else
        std::cout << RED << "ERROR: Created unknown materia!" << RESET << std::endl;

    delete src;
}

// 3. Test Character Inventory Limits (Equipping > 4 items)
// DOES IT LEAK the 5th item?
void testInventoryLimits() {
    printHeader("INVENTORY LIMITS");
    ICharacter* bob = new Character("Bob");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    std::cout << "Equipping 4 slots..." << std::endl;
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));

    std::cout << "Equipping 5th item (Should not equip)..." << std::endl;
    AMateria* extra = src->createMateria("ice");
    bob->equip(extra); 
    delete extra; 
    
    // Test equipping NULL
    std::cout << "Equipping NULL..." << std::endl;
    bob->equip(0); // Should not crash

    delete bob;
    delete src;
}

// 4. Test Deep Copy (The Clone Wars)
// If you modify the copy, does the original change? (It shouldn't!)
void testDeepCopy() {
    printHeader("DEEP COPY CHECK");
    
    Character* original = new Character("Original");
    AMateria* ice = new Ice();
    original->equip(ice);

    std::cout << "Creating Copy..." << std::endl;
    Character* copy = new Character(*original); // Copy Constructor

    std::cout << "Original name: " << original->getName() << std::endl;
    std::cout << "Copy name: " << copy->getName() << std::endl;

    std::cout << "Unequipping from Original (putting in its GC)..." << std::endl;
    original->unequip(0); // If shallow copy, this might mess up 'copy' too!

    std::cout << "Using Copy's item (Should still exist)..." << std::endl;
    // We need a dummy target
    Character* target = new Character("Target");
    copy->use(0, *target); // Should work if Deep Copy is correct

    delete target;
    delete copy;
    delete original;
}

// 5. The "Litterbug" Test (Garbage Collector Stress)
// Unequip everything and verify destructors clean up the floor.
void testGarbageCollector() {
    printHeader("GARBAGE COLLECTOR STRESS");
    Character* hoarder = new Character("Hoarder");
    
    hoarder->equip(new Ice());
    hoarder->equip(new Cure());
    hoarder->equip(new Ice());
    
    std::cout << "Unequipping all items (dropping to floor)..." << std::endl;
    hoarder->unequip(0);
    hoarder->unequip(1);
    hoarder->unequip(2);
    
    std::cout << "Equipping new items..." << std::endl;
    hoarder->equip(new Cure());
    hoarder->unequip(0); // Drop that one too

    std::cout << "Deleting Hoarder (Should clean up 4 dropped items)..." << std::endl;
    delete hoarder;
}

int main() {
    testSubject();
    testMateriaSourceLimits();
    testInventoryLimits();
    testDeepCopy();
    testGarbageCollector();
    
    std::cout << "\n" << GREEN << "All tests finished. CHECK VALGRIND!" << RESET << std::endl;
    return 0;
}