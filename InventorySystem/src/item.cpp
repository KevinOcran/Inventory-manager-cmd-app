//
// Created by Kevin  on 08/06/2025.
//

#include "../include/item.h"

#include <iostream>
#include <utility>

item::item(std::string name, std::string id, double price, int quantity, std::string  type)
    : name(std::move(name)), id(std::move(id)), price(price), quantity(quantity), type(std::move(type)) {}


void item::displayInfo() const {
    std::cout<<"Item: "<<name<<" | id: "<<id<<" | price: $"<<price
                <<" | quantity: "<<quantity<<std::endl;
}

std::string item::getName() const {
    return name;
}

std::string item::getId() const {
    return id;
}

double item::getPrice() const {
    return price;
}

int item::getQuantity() const {
    return quantity;
}

std::string item::getType() const {
    return type;
}


void item::setName(const std::string &name) {
    this->name = name;
}
void item::setId(const std::string& id) {
    this->id = id;
}

void item::setPrice(const double price) {
    this->price = price;
}

void item::setQuantity(const int quantity) {
    this->quantity = quantity;
}

void item::setType(const std::string& type) {
    this->type = type;
}



