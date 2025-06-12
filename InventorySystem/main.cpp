//
// Created by Kevin  on 08/06/2025.
//





#include <iostream>
#include <vector>
#include "include/item.h"
#include "include/csv_utils.h"
#include <algorithm>


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
                 << "7. Exit\n"
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
    if (normalizedInput == "7" || normalizedInput.find("exit") != std::string::npos)
        return "exit";

    return "invalid";
}


int main() {
    std::vector<item> inventory;  // Our dynamic in-memory store

    std::cout << "🔧 Inventory Management System Started\n";

    while (true) {
        std::string command = printMenuAndGetCommand();

        if (command == "add") {
            std::string name;
            int id;
            double price;
            int quantity;

            std::cout << "Enter item name: ";
            std::getline(std::cin, name);

            std::cout << "Enter item ID: ";
            std::cin >> id;

            std::cout << "Enter item price: ";
            std::cin >> price;

            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            inventory.emplace_back(name, id, price, quantity);
            std::cout << "✅ Item added successfully!\n";
        }

        else if (command == "remove") {
            int id;
            std::cout << "Enter item ID to remove: ";
            std::cin >> id;
            std::cin.ignore();

            auto it = std::remove_if(inventory.begin(), inventory.end(),
                [id](const item& item) {
                    return item.getId() == id;
                });

            if (it != inventory.end()) {
                inventory.erase(it, inventory.end());
                std::cout << "🗑️ Item removed.\n";
            } else {
                std::cout << "❌ Item not found.\n";
            }
        }

        else if (command == "update") {
            int id;
            int newQuantity;
            std::cout << "Enter item ID to update: ";
            std::cin >> id;

            std::cout << "Enter new quantity: ";
            std::cin >> newQuantity;
            std::cin.ignore();

            bool found = false;
            for (auto& item : inventory) {
                if (item.getId() == id) {
                    item.setQuantity(newQuantity);
                    std::cout << "✅ Quantity updated.\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "❌ Item not found.\n";
        }

        else if (command == "display") {
            if (inventory.empty()) {
                std::cout << "📭 No items to display.\n";
            } else {
                std::cout << "📋 Inventory:\n";
                for (const auto& item : inventory) {
                    item.displayInfo();
                }
            }
        }

        else if (command == "save") {
            std::string filename = "inventory.csv";
            csv_utils::saveToCSV(inventory, filename);
            std::cout << "✅ Inventory saved to file.\n";
        }

        else if (command == "load") {
            std::string filename = "inventory.csv";
            csv_utils::loadFromCSV(inventory, filename);
            std::cout << "📥 Inventory loaded from file:\n";
            for (const auto& item : inventory) {
                item.displayInfo();
            }
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






