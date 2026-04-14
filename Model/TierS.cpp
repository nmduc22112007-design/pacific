//
// Created by PC on 4/9/2026.
//

#include "../Model/TierS.h"


TierS::TierS(const std::string& ngay,
             const std::string& zone,
             const std::string& seat)
    : Ve(ngay, zone, seat, 1299000) {}

double TierS::tinhHeSoGia() const {
    return 1.0;
}

std::string TierS::getTenTier() const {
    return "TierS";
}


