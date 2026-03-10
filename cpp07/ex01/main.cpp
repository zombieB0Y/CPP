#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void multiplyByTwo(T& element) {
    element *= 2;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    ::iter(intArray, intSize, ::printElement<int>);
    std::cout << std::endl;

    ::iter(intArray, intSize, ::multiplyByTwo<int>);
    ::iter(intArray, intSize, ::printElement<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.5, 2.5, 3.5};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    ::iter(doubleArray, doubleSize, ::multiplyByTwo<double>);
    ::iter(doubleArray, doubleSize, ::printElement<double>);
    std::cout << std::endl;

    std::string stringArray[] = {"1337", "42", "network"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    ::iter(stringArray, stringSize, ::printElement<std::string>);
    std::cout << std::endl;

    const char constArray[] = {'a', 'b', 'c'};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);

    ::iter(constArray, constSize, ::printElement<char>);
    std::cout << std::endl;

    return 0;
}