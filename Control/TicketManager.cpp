#include "TicketManager.h"
#include "../Utils/CSVReader.h"

#include <iostream>

// ===== LOAD KHACH HANG TU CSV =====
void TicketManager::loadKhachHangCSV(const std::string& path) {
    auto rows = CSVReader::readCSV(path);

    for (const auto& r : rows) {
        if (r.size() < 3) continue;

        std::string maKH = r[0];
        std::string ten  = r[1];
        std::string sdt  = r[2];
        dsKhachHang.push_back(
            std::make_shared<KhachHang>(r[0], r[1], r[2])
            );
        }


    std::cout << "[INFO] Da load "
              << dsKhachHang.size()
              << " khach hang tu CSV.\n";
}

// ===== GET DANH SACH KHACH HANG =====
std::vector<std::shared_ptr<KhachHang>>&
TicketManager::getDanhSachKhachHang() {
    return dsKhachHang;
}

// ===== TIM KHACH HANG THEO MA =====
std::shared_ptr<KhachHang>
TicketManager::timKhachHangTheoMa(const std::string& maKH) {
    for (auto& kh : dsKhachHang) {
        if (kh->getMaKH() == maKH)
            return kh;
    }
    return nullptr;
}