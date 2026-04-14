//
// Created by PC on 4/9/2026.
//

#include "TierA.h"

TierA::TierA(const std::string& ngay,
             const std::string& zone,
             const std::string& seat)
    : Ve(ngay, zone, seat, 779000) {}

double TierA::tinhHeSoGia() const {
    return 1.0;
}

std::string TierA::getTenTier() const {
    return "TierA";
}

