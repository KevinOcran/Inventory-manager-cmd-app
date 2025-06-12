//
// Created by Kevin  on 09/06/2025.
//

#include "csv_utils.h"
#include "inventory_manager.h"
#include <iostream>
#include <limits> // for std::numeric_limits


void InventoryManager::addItem() {
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

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    items.emplace_back(name, id, price, quantity);
    std::cout << "✅ Item added successfully!\n";
}



void InventoryManager::removeItem() {
    int id;
    std::cout << "Enter ID of item to remove: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    const auto it = std::remove_if(items.begin(), items.end(), [id](const item& i) {
        return i.getId() == id;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "🗑️ Item removed successfully!\n";
    } else {
        std::cout << "⚠️ No item found with ID: " << id << "\n";
    }
}


void InventoryManager::updateQuantity() {
    int id;
    std::cout << "Enter ID of item to update quantity: ";
    std::cin >> id;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Search for the item
    for (auto& i : items) {
        if (i.getId() == id) {
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

    std::cout << "⚠️ No item found with ID: " << id << "\n";
}



void InventoryManager::displayAllItems() const {
    if (items.empty()) {
        std::cout << "📭 Inventory is empty.\n";
        return;
    }

    std::cout << "\n📦 Current Inventory:\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Name\t\t| ID\t| Price\t\t| Quantity\n";
    std::cout << "------------------------------------------------------------\n";

    for (const auto& item : items) {
        std::cout << item.getName() << "\t| "
                  << item.getId() << "\t| $"
                  << item.getPrice() << "\t| "
                  << item.getQuantity() << "\n";
    }

    std::cout << "------------------------------------------------------------\n";
}




void InventoryManager::saveToCSV(const std::string& filename) const {
    csv_utils::saveToCSV(items, filename);
    std::cout << "✅ Inventory saved to " << filename << "\n";
}

void InventoryManager::loadFromCSV(const std::string& filename) {
    csv_utils::loadFromCSV(items, filename);
    std::cout << "📥 Inventory loaded from " << filename << "\n";
}
const std::vector<item>& InventoryManager::getItems() const {
    return items;
}





