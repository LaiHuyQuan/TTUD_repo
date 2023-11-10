#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> database;
    std::string key;

    // Read the keys and insert them into the database
    while (true) {
        std::cin >> key;
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    // Process find and insert commands
    while (true) {
        std::string command, query;
        std::cin >> command;

        if (command == "***") {
            break;
        }

        std::cin >> query;

        if (command == "find") {
            if (database.find(query) != database.end()) {
                std::cout << "1" << std::endl;  // Key exists
            } else {
                std::cout << "0" << std::endl;  // Key not found
            }
        } else if (command == "insert") {
            if (database.find(query) != database.end()) {
                std::cout << "0" << std::endl;  // Insertion failed, key already exists
            } else {
                database.insert(query);
                std::cout << "1" << std::endl;  // Insertion successful
            }
        }
    }

    return 0;
}
