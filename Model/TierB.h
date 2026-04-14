//
// Created by PC on 4/9/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_TIERB_H
#define VCT_PACIFIC_STAGE_1_TIERB_H
#pragma once
#include "Ve.h"

class TierB : public Ve {
public:
    TierB(const std::string& ngay,
          const std::string& zone,
          const std::string& seat);

    double tinhHeSoGia() const override;
    std::string getTenTier() const override;
};

#endif //VCT_PACIFIC_STAGE_1_TIERB_H