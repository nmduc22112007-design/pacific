//
// Created by PC on 4/9/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_THREEDAYPASS_H
#define VCT_PACIFIC_STAGE_1_THREEDAYPASS_H

#include "../Model/Ve.h"

class ThreeDayPass : public Ve {
public:
    ThreeDayPass(const std::string& zone,
                 const std::string& seat);

    double tinhHeSoGia() const override;
    std::string getTenTier() const override;
};



#endif //VCT_PACIFIC_STAGE_1_THREEDAYPASS_H