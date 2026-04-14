//
// Created by PC on 4/9/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_TIERS_H
#define VCT_PACIFIC_STAGE_1_TIERS_H
#pragma once
#include "Ve.h"

class TierS : public Ve {
public:
    TierS(const std::string& ngay,
          const std::string& zone,
          const std::string& seat);

    double tinhHeSoGia() const override;
    std::string getTenTier() const override;
};

#endif //VCT_PACIFIC_STAGE_1_TIERS_H