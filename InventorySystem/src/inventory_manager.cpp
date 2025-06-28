//
// Created by Kevin  on 09/06/2025.
//

#include "csv_utils.h"
#include "inventory_manager.h"

#include <iomanip>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <sstream>


void InventoryManager::addItem() {
    std::string name;
    double price;
    int quantity;
    std::string type;

    std::cout << "Enter item type: ";
    std::getline(std::cin, type);  // handles multi-word input!

    std::cout << "Enter item name: ";
    std::getline(std::cin, name);

    std::cout << "Enter item price: ";
    std::cin >> price;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;



    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::stringstream idStream;

    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    int year = localTime->tm_year + 1900;

    idStream << "INV-" << year << "-"
         << std::setw(4) << std::setfill('0') << nextId++;

    std::string styledId = idStream.str();

    items.emplace_back(name, styledId, price, quantity, type);

    std::cout << "✅ Item added with auto-assigned ID: " << (nextId - 1) << "\n";
}



void InventoryManager::removeItem() {
    int idNum;
    std::cout << "Enter ID number to remove (e.g. 12 for INV-2025-0012): ";
    std::cin >> idNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    const auto it = std::remove_if(items.begin(), items.end(), [idNum](const item& i) {
        std::string fullId = i.getId();
        size_t lastDash = fullId.rfind('-');
        if (lastDash != std::string::npos) {
            std::string numPart = fullId.substr(lastDash + 1);
            return std::stoi(numPart) == idNum;
        }
        return false;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "🗑️ Item removed successfully!\n";
    } else {
        std::cout << "⚠️ No item found with numeric ID: " << idNum << "\n";
    }
}



void InventoryManager::updateQuantity() {
    int idNum;
    std::cout << "Enter ID number to update (e.g. 12 for INV-2025-0012): ";
    std::cin >> idNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (auto& i : items) {
        std::string fullId = i.getId();
        size_t lastDash = fullId.rfind('-');
        if (lastDash != std::string::npos) {
            std::string numPart = fullId.substr(lastDash + 1);
            if (std::stoi(numPart) == idNum) {
                int newQty;
                std::cout << "Current quantity: " << i.getQuantity() << "\n";
                std::cout << "Enter new quantity: ";
                std::cin >> newQty;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (newQty >= 0) {
                    i.setQuantity(newQty);
                    std::cout << "🔁 Quantity updated successfully!\n";
                } else {
                    std::cout << "❌ Quantity cannot be negative.\n";
                }
                return;
            }
        }
    }

    std::cout << "⚠️ No item found with numeric ID: " << idNum << "\n";
}



void InventoryManager::displayAllItems() const {
    if (items.empty()) {
        std::cout << "📭 Inventory is empty.\n";
        return;
    }

    std::cout << "\n📦 Current Inventory:\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Name\t\t| ID\t\t\t| Price\t| Quantity\t| Type\n";
    std::cout << "------------------------------------------------------------\n";


for (const auto& item : items) {
    std::cout << item.getName() << "\t| "
              << item.getId() << "\t| $"
              << item.getPrice() << "\t| "
              << item.getType() << "\t\t"
              << item.getQuantity() << "\n| ";

}

    std::cout << "------------------------------------------------------------\n";
}


void InventoryManager::searchByType(const std::string &search) const {
    bool found = false;
    for (const auto& item : items) {
        if (item.getType() == search || item.getName() == search || item.getId() == search) {
            std::cout << item.getName() << "\t| "
          << item.getId() << "\t| $"
          << item.getPrice() << "\t| "
          << item.getType() << "\t\t"
          << item.getQuantity() << "\n| ";

            std::cout << "------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No such item found.\n";
    }

}





void InventoryManager::saveToCSV(const std::string& filename) const {
    csv_utils::saveToCSV(items, filename);
    std::cout << "✅ Inventory saved to " << filename << "\n";
}

void InventoryManager::loadFromCSV(const std::string& filename) {
    csv_utils::loadFromCSV(items, filename);
    std::cout << "📥 Inventory loaded from " << filename << "\n";
    int maxNum = 0;
    for (const auto& i : items) {
        std::string id = i.getId(); // e.g., "INV-2025-0042"
        size_t lastDash = id.rfind('-');
        if (lastDash != std::string::npos) {
            std::string numStr = id.substr(lastDash + 1);
            int num = std::stoi(numStr);
            if (num > maxNum) maxNum = num;
        }
    }
    nextId = maxNum + 1;



}
const std::vector<item>& InventoryManager::getItems() const {
    return items;
}





