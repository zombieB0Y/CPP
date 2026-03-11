#include "Array.hpp"

int main() {
    Array<int> emptyArr;
    std::cout << emptyArr.size() << std::endl;

    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = i * 2;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> copyArr(arr);
    arr[0] = 42;
    std::cout << arr[0] << " " << copyArr[0] << std::endl;

    Array<int> assignArr;
    assignArr = copyArr;
    copyArr[1] = 1337;
    std::cout << copyArr[1] << " " << assignArr[1] << std::endl;

    try {
        arr[5] = 100;
        std::cout << "This should not print." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Index out of bounds!" << std::endl;
    }

    try {
        emptyArr[0] = 1;
        std::cout << "This should not print." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Empty array out of bounds!" << std::endl;
    }

    return 0;
}