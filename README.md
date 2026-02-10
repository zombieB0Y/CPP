# 42 C++ Modules (00 - 05)

This repository contains my solutions for the **C++ Piscine Modules 00 through 05** at 42.
The goal of these modules is to transition from **C** to **Object-Oriented Programming (OOP)** using **C++98**.

## 🛠️ General Rules
* **Language:** C++98 Standard.
* **Compilation:** `c++ -Wall -Wextra -Werror -std=c++98`
* **Forbidden:**
    * `*alloc`, `free`, `printf`.
    * STL Containers (Vectors, Lists, Maps) *until Module 08*.
    * `using namespace <ns>`.

---

## 📚 Module Breakdown

### [Module 00: Namespace, Class, Member Functions](cpp00/)
*Introduction to C++ syntax and basic OOP concepts.*

* **Key Concepts:**
    * **Namespaces:** Avoiding naming collisions.
    * **Classes & Objects:** Encapsulation of data and behavior.
    * **Access Specifiers:** `public` vs `private`.
    * **Input/Output Streams:** `std::cin`, `std::cout`, `std::endl`.
    * **Initialization Lists:** Initializing const members and references.
    * **Const correctness:** `const` member functions.

### [Module 01: Memory Allocation, Pointers, References](cpp01/)
*Understanding memory management and the relationship between pointers and references.*

* **Key Concepts:**
    * **New & Delete:** Dynamic memory allocation in C++.
    * **References (`&`):** Safer, non-null aliases for variables.
    * **Pointers to Members:** Accessing class members via pointers.
    * **The Switch Statement:** Clean control flow.
    * **File I/O:** Reading and replacing text in files.

### [Module 02: Ad-hoc Polymorphism, Operator Overloading](cpp02/)
*Deep dive into classes, canonical forms, and number representation.*

* **Key Concepts:**
    * **Orthodox Canonical Form (OCF):** The 4 required functions for a robust class:
        1.  Default Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor
    * **Operator Overloading:** Customizing behavior for operators like `=`, `+`, `<<`.
    * **Fixed-Point Numbers:** Implementing a number class that balances performance and precision (alternative to floating point).

### [Module 03: Inheritance](cpp03/)
*Building hierarchies and sharing code between classes.*

* **Key Concepts:**
    * **Inheritance:** Creating "Child" classes derived from "Parent" classes.
    * **Access Specifiers:** The `protected` keyword.
    * **Shadowing:** How derived classes can override base variables/functions.
    * **Diamond Problem:** (Touched upon conceptually) Issues with multiple inheritance.

### [Module 04: Subtype Polymorphism, Abstract Classes, Interfaces](cpp04/)
*The most critical module for understanding strict OOP.*

* **Key Concepts:**
    * **Polymorphism:** Treating derived objects as their base class (`Animal* a = new Dog()`).
    * **Virtual Functions:** Enabling dynamic dispatch (runtime decision making).
    * **Abstract Classes:** Classes that cannot be instantiated (`= 0`).
    * **Interfaces:** Pure abstract classes that define behavior contracts.
    * **Virtual Destructors:** **CRITICAL** for preventing memory leaks when deleting derived objects via base pointers.
    * **Deep vs. Shallow Copy:** Manually cloning memory to ensure independent objects.

### [Module 05: Repetition and Exceptions](cpp05/)
*A simulation of corporate bureaucracy to master robust error handling.*

* **Key Concepts:**
    * **Exception Handling:** Managing runtime errors gracefully using `try`, `catch`, and `throw` blocks.
    * **Standard Exceptions:** Creating custom exception classes that inherit from `std::exception`.
    * **Nested Classes:** Defining exceptions inside the scope of other classes (e.g., `Bureaucrat::GradeTooHighException`).
    * **Control Flow:** Understanding how exceptions interrupt normal execution and trigger stack unwinding.
    * **Abstract Classes (Recap):** Using `AForm` as a base for concrete forms (`Shrubbery`, `Robotomy`, `Pardon`).
    * **Factory Pattern:** Dynamically creating specific form objects using a central "Intern" maker.
---

## 🧠 Key Learnings & Pitfalls

### 1. The Orthodox Canonical Form (OCF)
Mandatory for classes that manage resources (like memory).
```cpp
class A {
    public:
        A();                            // Default
        A(const A &copy);               // Copy Constructor
        A &operator=(const A &other);   // Assignment Operator
        ~A();                           // Destructor
};