//
// Created by PC on 4/14/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_SEATVALIDATOR_H
#define VCT_PACIFIC_STAGE_1_SEATVALIDATOR_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>



class SeatValidator {
public:
    static bool normalizeSeat(std::string& seat, std::string& zone) {
        // Chuẩn hóa về chữ hoa
        for (char& c : seat)
            c = std::toupper(static_cast<unsigned char>(c));

        zone.clear();
        std::string number;

        for (char c : seat) {
            if (std::isalpha(static_cast<unsigned char>(c)))
                zone += c;
            else if (std::isdigit(static_cast<unsigned char>(c)))
                number += c;
            else
                return false;
        }

        // Zone phải đúng 1 ký tự
        if (zone.length() != 1)
            return false;

        if (number.empty())
            return false;

        int seatNum = std::stoi(number);
        return seatNum >= 1 && seatNum <= 99;
    }

    static bool isValidSeat(const std::string& tier,
                            const std::string& zone) {
        static const std::map<std::string, std::vector<std::string>> seatMap = {
            {"TierB", {"A","B","D","E","H","I","L","M","P"}},
            {"TierA", {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"}},
            {"TierS", {"B","C","F","G","J","K","N","O"}},
            {"3DayPass", {"B","C","F","G","J","K","N","O"}}
        };

        auto it = seatMap.find(tier);
        if (it == seatMap.end()) return false;

        const auto& allowedZones = it->second;
        return std::find(allowedZones.begin(),
                         allowedZones.end(),
                         zone) != allowedZones.end();
    }

    static std::vector<std::string> getAllowedSeats(const std::string& tier) {
        static const std::map<std::string, std::vector<std::string>> seatMap = {
            {"TierB", {"A","B","D","E","H","I","L","M","P"}},
            {"TierA", {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"}},
            {"TierS", {"B","C","F","G","J","K","N","O"}},
            {"3DayPass", {"B","C","F","G","J","K","N","O"}}
        };
        return seatMap.at(tier);
    }
};

#endif //VCT_PACIFIC_STAGE_1_SEATVALIDATOR_H