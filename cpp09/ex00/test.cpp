#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    // Open the file stream
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string line;
    // Step 1: Split the file into individual lines
    std::getline(file, line);
        
        std::istringstream lineStream(line);
        std::string token;

        // Step 2: Split the current line by a delimiter (e.g., a comma)
        while (std::getline(lineStream, token, ',')) {
            std::cout << "Token: " << token << "\n";
        }
    
    file.close();
    return 0;
}
