//
// Created by Kevin  on 08/06/2025.
//

#include "../include/item.h"

#include <iostream>
#include <utility>

item::item(std::string name, int id, double price, int quantity) : name(std::move(name)), id(id), price(price), quantity(quantity) {}

void item::displayInfo() const {
    std::cout<<"Item: "<<name<<" | id: "<<id<<" | price: $"<<price
                <<" | quantity: "<<quantity<<std::endl;
}

std::string item::getName() const {
    return name;
}

int item::getId() const {
    return id;
}

double item::getPrice() const {
    return price;
}

int item::getQuantity() const {
    return quantity;
}

void item::setName(const std::string &name) {
    this->name = name;
}
void item::setId(const int id) {
    this->id = id;
}

void item::setPrice(const double price) {
    this->price = price;
}

void item::setQuantity(const int quantity) {
    this->quantity = quantity;
}



