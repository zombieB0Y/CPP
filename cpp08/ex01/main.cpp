#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main() {
    std::cout << "--- 1. SUBJECT BASIC TEST ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
    }

    std::cout << "\n--- 2. EXCEPTION: NOT ENOUGH ELEMENTS ---" << std::endl;
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception safely caught: Need at least 2 elements." << std::endl;
    }

    std::cout << "\n--- 3. EXCEPTION: ADDING BEYOND CAPACITY ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (std::exception &e) {
        std::cout << "Exception safely caught: Span is full." << std::endl;
    }

    std::cout << "\n--- 4. NEGATIVE NUMBERS & ABSOLUTE MATH ---" << std::endl;
    try {
        Span sp(4);
        sp.addNumber(-100);
        sp.addNumber(100);
        sp.addNumber(-50);
        sp.addNumber(-55);
        std::cout << "Shortest (expect 5): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest (expect 200): " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
    }

    std::cout << "\n--- 5. HUGE CAPACITY TEST (100,000 ELEMENTS) ---" << std::endl;
    try {
        Span sp(100000);
        std::vector<int> bigVec;
        for (int i = 0; i < 100000; i++) {
            bigVec.push_back(i * 2);
        }
        sp.addNumber(bigVec.begin(), bigVec.end());
        std::cout << "Shortest (expect 2): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest (expect 199998): " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
    }

    std::cout << "\n--- 6. RANGE ITERATORS: STD::LIST ---" << std::endl;
    try {
        Span sp(10);
        std::list<int> lst;
        lst.push_back(50);
        lst.push_back(100);
        lst.push_back(1000);

        sp.addNumber(lst.begin(), lst.end());
        std::cout << "Shortest (expect 50): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest (expect 950): " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
    }

    std::cout << "\n--- 7. EXCEPTION: RANGE ADD EXCEEDING CAPACITY ---" << std::endl;
    try {
        Span sp(2);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        sp.addNumber(vec.begin(), vec.end());
        std::cout << "This should not print." << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception safely caught: Range exceeds maximum capacity." << std::endl;
    }

    return 0;
}