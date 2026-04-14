
#ifndef VCT_PACIFIC_STAGE_1_TICKERMANAGER_H
#define VCT_PACIFIC_STAGE_1_TICKERMANAGER_H

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../Model/KhachHang.h"

class TicketManager {
private:
    std::vector<std::shared_ptr<KhachHang>> dsKhachHang;

public:
    // ===== LOAD DU LIEU =====
    void loadKhachHangCSV(const std::string& path);

    // ===== GETTER =====
    std::vector<std::shared_ptr<KhachHang>>& getDanhSachKhachHang();

    // ===== TIEN ICH =====
    std::shared_ptr<KhachHang> timKhachHangTheoMa(const std::string& maKH);
};


#endif //VCT_PACIFIC_STAGE_1_TICKERMANAGER_H