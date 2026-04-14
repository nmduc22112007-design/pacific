//
// Created by PC on 4/9/2026.
//

#include "../Model/TierB.h"

TierB::TierB(const std::string& ngay,
             const std::string& zone,
             const std::string& seat)
    : Ve(ngay, zone, seat, 399000) {}

double TierB::tinhHeSoGia() const {
    return 1.0;
}

std::string TierB::getTenTier() const {
    return "TierB";
}

