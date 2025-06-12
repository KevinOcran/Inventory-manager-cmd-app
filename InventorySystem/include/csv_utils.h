//
// Created by Kevin  on 09/06/2025.
//

#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include <vector>
#include "item.h"
#include <string>



namespace csv_utils {
    void saveToCSV(const std::vector<item>& items, const std::string& filename);

    void loadFromCSV(std::vector<item>& items, const std::string& filename);
}




#endif //CSV_UTILS_H
