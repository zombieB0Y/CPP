#include "Serializer.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST 1: STACK MEMORY ---" << std::endl;
    Data stackData;
    stackData.name = "Original Name";
    stackData.age = 42;
    stackData.isStudent = true;

    std::cout << "Original address:     " << &stackData << std::endl;

    uintptr_t raw = Serializer::serialize(&stackData);
    std::cout << "Serialized (integer): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << deserializedData << std::endl;

    if (&stackData == deserializedData) { // 
        std::cout << "SUCCESS: Addresses match!" << std::endl;
        std::cout << "Data intact -> Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;
    } else {
        std::cout << "FAIL: Addresses do not match!" << std::endl;
    }

    std::cout << "\n--- TEST 2: NULL POINTER ---" << std::endl;
    Data* nullPtr = NULL;
    uintptr_t rawNull = Serializer::serialize(nullPtr);
    // std::cout << rawNull << std::endl;
    Data* deserializedNull = Serializer::deserialize(rawNull);
    
    if (deserializedNull == NULL) {
        std::cout << "SUCCESS: Null pointer serialized and deserialized safely!" << std::endl;
    }

    std::cout << "\n--- TEST 3: HEAP MEMORY & MUTATION ---" << std::endl;
    Data* heapData = new Data;
    heapData->name = "Heap Data";
    heapData->age = 100;

    uintptr_t rawHeap = Serializer::serialize(heapData);
    Data* ptrHeap = Serializer::deserialize(rawHeap);

    ptrHeap->age = 999; 

    if (heapData->age == 999) {
        std::cout << "SUCCESS: Mutation worked, they point to the exact same block of memory!" << std::endl;
    }
    delete heapData; 
    return 0;
}