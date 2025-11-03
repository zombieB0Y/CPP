#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string line;

    while (true)
    {
        std::cout << "PhoneBook> ";
        if (!std::getline(std::cin, line))
        {
            std::cout << std::endl;
            break;
        }
        if (line == "EXIT")
            break;
        else if (line == "ADD")
            phonebook.ADD();
        else if (line == "SEARCH")
            phonebook.SEARCH();
        else if (line.empty())
            continue;
        else
        {
            std::cout << "Unknown command: " << line << "\n";
            std::cout << "Available commands: ADD, SEARCH, EXIT\n";
        }
    }

    return 0;
}