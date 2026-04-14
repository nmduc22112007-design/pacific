//
// Created by PC on 4/9/2026.
//

#include "ThreeDayPass.h"

ThreeDayPass::ThreeDayPass(const std::string& zone,
                           const std::string& seat)
    : Ve("15-16-17/05/2026", zone, seat, 3315000) {}

double ThreeDayPass::tinhHeSoGia() const {
    return 1.0;
}

std::string ThreeDayPass::getTenTier() const {
    return "3DayPass";
}
