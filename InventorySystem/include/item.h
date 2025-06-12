//
// Created by Kevin  on 08/06/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>


class item {
private:
    std::string name;
    int id;
    double price;
    int quantity;
public:
    item(std::string name, int id, double price, int quantity);

    void displayInfo() const;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getId() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] int getQuantity() const;

    void setName(const std::string &name);
    void setId(int id);
    void setPrice(double price);
    void setQuantity(int quantity);


};



#endif //ITEM_H
