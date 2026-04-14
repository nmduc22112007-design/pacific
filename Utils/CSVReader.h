//
// Created by PC on 4/14/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_CSVREADER_H
#define VCT_PACIFIC_STAGE_1_CSVREADER_H


#include <string>
#include <vector>

class CSVReader {
public:
    static std::vector<std::vector<std::string>>
    readCSV(const std::string& filePath);
};

#endif //VCT_PACIFIC_STAGE_1_CSVREADER_H