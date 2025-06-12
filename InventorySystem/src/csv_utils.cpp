//
// Created by Kevin  on 09/06/2025.
//

#include "../include/csv_utils.h"

#include <fstream>
#include <iostream>
#include <sstream>

void saveToCSV(const std::vector<item> &items, const std::string &filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "❌Failed to open file " << filename << std::endl ;
    }
    outFile << "name,id,price,quantity\n";


    for (const auto& item : items) {
        outFile<<item.getName()<<" , "
        <<item.getId()<<" , "
        <<item.getPrice()<<" , "
        <<item.getQuantity()<<"\n";
    }
    outFile.close();
}

void loadFromCSV(std::vector<item> &items, const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "⚠️ Warning: Could not open file " << filename <<" for reading"<< std::endl ;
    }

    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string itemName;
        int itemId;
        double itemPrice;
        int itemQuantity;
        std::string field;


        std::getline(ss, itemName, ',');

        std::getline(ss,field,',');
        itemId = std::stoi(field);

        std::getline(ss,field,',');
        itemPrice = std::stod(field);

        std::getline(ss, field,',');
        itemQuantity = std::stoi(field);

        items.emplace_back(itemName,itemId,itemPrice,itemQuantity);
    }
    inFile.close();


}


