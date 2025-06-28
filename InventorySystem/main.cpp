//
// Created by Kevin  on 08/06/2025.
//





#include <iostream>
#include <vector>
#include "include/item.h"
#include "include/csv_utils.h"
#include <algorithm>

#include "inventory_manager.h"


std::string tolower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return result;
}



std::string printMenuAndGetCommand() {
    std::cout << "\n====== Inventory Menu ======\n"
                 << "1. Add New Item\n"
                 << "2. Remove Item\n"
                 << "3. Update Quantity\n"
                 << "4. Display All Items\n"
                 << "5. Save to CSV\n"
                 << "6. Load from CSV\n"
                 << "7. Search Items\n"
                 << "8. Exit\n"
                 << "Enter your choice (number or full command): ";

    std::string input;
    std::getline(std::cin, input);
    std::string normalizedInput = tolower(input);

    if (normalizedInput == "1" || normalizedInput.find("add") != std::string::npos)
        return "add";
    if (normalizedInput == "2" || normalizedInput.find("remove") != std::string::npos)
        return "remove";
    if (normalizedInput == "3" || normalizedInput.find("update") != std::string::npos)
        return "update";
    if (normalizedInput == "4" || normalizedInput.find("display") != std::string::npos)
        return "display";
    if (normalizedInput == "5" || normalizedInput.find("save") != std::string::npos)
        return "save";
    if (normalizedInput == "6" || normalizedInput.find("load") != std::string::npos)
        return "load";
    if (normalizedInput == "7" || normalizedInput.find("search") != std::string::npos)
        return "search";
    if (normalizedInput == "8" || normalizedInput.find("exit") != std::string::npos)
        return "exit";

return "invalid";
}


int main() {
    InventoryManager manager;


    std::vector<item> inventory;  // Our dynamic in-memory store

    std::cout << "🔧 Inventory Management System Started\n";

    while (true) {
        std::string command = printMenuAndGetCommand();

        if (command == "add") {
            manager.addItem();
        }

        else if (command == "remove") {
            manager.removeItem();
        }

        else if (command == "update") {
            manager.updateQuantity();
        }

        else if (command == "display") {
            manager.displayAllItems();
        }


        else if (command == "save") {
            manager.saveToCSV("inventory.csv");
        }


        else if (command == "load") {
            manager.loadFromCSV("inventory.csv");
        }

        else if (command == "search"){
            std::string search;
            std::cout << "Search Items: " << std::endl;
            std::getline(std::cin, search);
            manager.searchByType(search);
        }

        else if (command == "exit") {
            std::cout << "👋 Exiting Inventory Management System...\n";
            break;
        }

        else {
            std::cout << "⚠️ Invalid command. Please try again.\n";
        }
    }

    return 0;
}






