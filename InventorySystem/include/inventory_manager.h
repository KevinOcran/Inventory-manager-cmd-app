//
// Created by Kevin  on 09/06/2025.
//



#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "item.h"
#include <vector>
#include <string>

class InventoryManager {
private:
    int nextId = 1;
    std::vector<item> items;

public:
    void addItem();
    void removeItem();
    void updateQuantity();
    void displayAllItems() const;
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);
    void searchByType(const std::string& search) const;

    [[nodiscard]] const std::vector<item>& getItems() const;
};

#endif // INVENTORY_MANAGER_H

