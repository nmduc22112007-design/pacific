#include "CSVReader.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>>
CSVReader::readCSV(const std::string& filePath) {

    std::vector<std::vector<std::string>> data;
    std::ifstream file(filePath);

    if (!file.is_open()) return data;

    std::string line;
    bool skipHeader = true;

    while (std::getline(file, line)) {
        if (skipHeader) {
            skipHeader = false;
            continue;
        }

        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    return data;
}