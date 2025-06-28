//
// Created by Kevin  on 08/06/2025.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
private:
    std::string name;
    std::string id;  // changed from int to string
    double price;
    int quantity;
    std::string type;

public:
    item(std::string name, std::string id, double price, int quantity, std::string  type);  // updated constructor

    void displayInfo() const;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getId() const;  // updated return type
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] int getQuantity() const;
    [[nodiscard]] std::string getType() const;

    void setName(const std::string& name);
    void setId(const std::string& id);  // updated setter
    void setPrice(double price);
    void setQuantity(int quantity);
    void setType(const std::string& type);
};

#endif // ITEM_H

