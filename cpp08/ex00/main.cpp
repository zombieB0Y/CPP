#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::const_iterator vecIt = easyfind(vec, 30);
        std::cout << "Found in vector: " << *vecIt << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: Value not found in vector!" << std::endl;
    }

    try {
        std::vector<int>::const_iterator vecItErr = easyfind(vec, 99);
        std::cout << "Found in vector: " << *vecItErr << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: Value not found in vector!" << std::endl;
    }

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);
    lst.push_back(500);

    try {
        std::list<int>::const_iterator lstIt = easyfind(lst, 500);
        std::cout << "Found in list: " << *lstIt << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: Value not found in list!" << std::endl;
    }

    try {
        std::list<int>::const_iterator lstItErr = easyfind(lst, 42);
        std::cout << "Found in list: " << *lstItErr << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: Value not found in list!" << std::endl;
    }

    return 0;
}