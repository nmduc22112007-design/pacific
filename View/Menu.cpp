#include "Menu.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

#include "../Model/TierB.h"
#include "../Model/TierA.h"
#include "../Model/TierS.h"
#include "../Model/ThreeDayPass.h"
#include "../Utils/Utils.h"
#include "../Utils/SeatValidator.h"

// ===== EXCEPTION =====
#include "../Exception/InvalidMatchDayException.h"
#include "../Exception/RefundQuantityException.h"
#include "../Exception/BaseException.h"
#include "../Exception/InvalidPhoneNumberException.h"
#include "../Exception/InvalidNameException.h"

// ===== TRANG THAI MUA VE =====
enum class TrangThaiMuaVe {
    THANH_CONG,
    LOI_GHE,
    LOI_GIOI_HAN,
    KHONG_LAM_GI
};

// ===== DANH SACH NGAY HOP LE =====
static const std::vector<std::string> NGAY_HOP_LE = {
    "15/05/2026",
    "16/05/2026",
    "17/05/2026"
};

// ===== HAM CHON GHE DUNG CHUNG =====

TrangThaiMuaVe xuLyChonGhe(const std::string& tier,
                           std::string& seat,
                           std::string& zone) {
    while (true) {
        std::cout << "Cac khu vuc ghe hop le cho " << tier << ": ";
        for (const auto& z : SeatValidator::getAllowedSeats(tier))
            std::cout << z << " ";
        std::cout << "\nNhap ghe (VD: B12): ";
        std::cin >> seat;

        if (!SeatValidator::normalizeSeat(seat, zone)) {
            std::cout << "[ERROR] Dinh dang ghe sai (VD: B12)\n";
            continue;
        }

        if (!SeatValidator::isValidSeat(tier, zone)) {
            std::cout << "[ERROR] Khu vuc " << zone
                      << " khong hop le cho " << tier << "\n";
            continue;
        }

        return TrangThaiMuaVe::THANH_CONG;
    }
}


// ===== HIEN THI MENU =====
void Menu::hienThiMenu() {
    std::cout << "\n===== HE THONG BAN VE VCT PACIFIC STAGE 1 =====\n";
    std::cout << "1. Mua ve Tier B\n";
    std::cout << "2. Mua ve Tier A\n";
    std::cout << "3. Mua ve Tier S\n";
    std::cout << "4. Mua ve 3-Day Pass (Tier S)\n";
    std::cout << "5. Hoan ve\n";
    std::cout << "0. Ket thuc\n";
    std::cout << "============================================\n";
}

// ===== MENU CHINH =====
void Menu::xuLyMenu(TicketManager& manager) {
    auto& dsKhachHang = manager.getDanhSachKhachHang();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string ten, sdt;

    // ===== NHAP TEN =====
    while (true) {
        try {
            std::cout << "Nhap ho ten: ";
            std::getline(std::cin, ten);

            if (ten.empty())
                throw InvalidNameException(ten);

            for (char c : ten)
                if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ')
                    throw InvalidNameException(ten);

            break;
        } catch (const BaseException& e) {
            std::cout << "[EXCEPTION] " << e.what() << "\n";
        }
    }

    // ===== NHAP SDT =====
    while (true) {
        try {
            std::cout << "Nhap so dien thoai: ";
            std::getline(std::cin, sdt);

            if (sdt.length() != 10)
                throw InvalidPhoneNumberException(sdt);

            for (char c : sdt)
                if (!std::isdigit(static_cast<unsigned char>(c)))
                    throw InvalidPhoneNumberException(sdt);

            break;
        } catch (const BaseException& e) {
            std::cout << "[EXCEPTION] " << e.what() << "\n";
        }
    }

    // ===== TAO KHACH HANG =====
    int soThuTu = static_cast<int>(dsKhachHang.size()) + 1;
    std::string maKH = (soThuTu < 10 ? "KH00" : "KH0") + std::to_string(soThuTu);

    auto khNguoiDung = std::make_shared<KhachHang>(maKH, ten, sdt);
    dsKhachHang.push_back(khNguoiDung);

    std::cout << "\n[OK] Da tao khach hang moi!\n";
    std::cout << "Ma khach hang: " << maKH << "\n";

    std::cout << "\n===== CHUYEN SANG MENU MUA VE =====\n";
    xuLyMuaVe(*khNguoiDung);
}

// ===== MENU MUA / HOAN VE =====
void Menu::xuLyMuaVe(KhachHang& kh) {
    int choice;

    do {
        try {
            hienThiMenu();
            std::cout << "Lua chon cua ban: ";
            std::cin >> choice;

            if (choice == 0) break;

            std::string ngay;
            if (choice >= 1 && choice <= 3) {
                std::cout << "Nhap ngay (15/05/2026 - 17/05/2026): ";
                std::cin >> ngay;

                if (std::find(NGAY_HOP_LE.begin(), NGAY_HOP_LE.end(), ngay)
                    == NGAY_HOP_LE.end())
                    throw InvalidMatchDayException(ngay);
            }

            TrangThaiMuaVe trangThai = TrangThaiMuaVe::KHONG_LAM_GI;

            switch (choice) {

                case 1: {
                    std::string seat, zone;
                    trangThai = xuLyChonGhe("TierB", seat, zone);
                    if (trangThai != TrangThaiMuaVe::THANH_CONG) break;

                    if (kh.daTonTaiGhe(ngay, zone, seat)) {
                        std::cout << "[ERROR] Ghe " << seat << " da duoc mua!\n";
                        break;
                    }

                    if (!kh.themVe(std::make_shared<TierB>(ngay, zone, seat)))
                        trangThai = TrangThaiMuaVe::LOI_GIOI_HAN;
                    else
                        trangThai = TrangThaiMuaVe::THANH_CONG;
                    break;
                }


                case 2: {
                    std::string seat, zone;
                    trangThai = xuLyChonGhe("TierA", seat, zone);
                    if (trangThai != TrangThaiMuaVe::THANH_CONG) break;

                    if (kh.daTonTaiGhe(ngay, zone, seat)) {
                        std::cout << "[ERROR] Ghe " << seat << " da duoc mua!\n";
                        break;
                    }

                    if (!kh.themVe(std::make_shared<TierA>(ngay, zone, seat)))
                        trangThai = TrangThaiMuaVe::LOI_GIOI_HAN;
                    else
                        trangThai = TrangThaiMuaVe::THANH_CONG;
                    break;
                }
                case 3: {
                    std::string seat, zone;
                    trangThai = xuLyChonGhe("TierS", seat, zone);
                    if (trangThai != TrangThaiMuaVe::THANH_CONG) break;

                    if (kh.daTonTaiGhe(ngay, zone, seat)) {
                        std::cout << "[ERROR] Ghe " << seat << " da duoc mua!\n";
                        break;
                    }

                    if (!kh.themVe(std::make_shared<TierS>(ngay, zone, seat)))
                        trangThai = TrangThaiMuaVe::LOI_GIOI_HAN;
                    else
                        trangThai = TrangThaiMuaVe::THANH_CONG;
                    break;
                }

                case 4: {
                    std::string seat, zone;
                    trangThai = xuLyChonGhe("3DayPass", seat, zone);
                    if (trangThai != TrangThaiMuaVe::THANH_CONG) break;

                    if (!kh.themVe(std::make_shared<ThreeDayPass>(zone, seat)))
                        trangThai = TrangThaiMuaVe::LOI_GIOI_HAN;
                    else
                        trangThai = TrangThaiMuaVe::THANH_CONG;
                    break;
                }

                case 5: {
                    if (kh.getSoLuongVe() == 0) {
                        std::cout << "[INFO] Khong co ve nao de hoan!\n";
                        break;
                    }
                    kh.hienThiThongTin();
                    // (Giữ nguyên logic hoàn vé cũ của bạn)
                    break;
                }

                default:
                    std::cout << "[ERROR] Lua chon khong hop le!\n";
                    continue;
            }

            if (choice >= 1 && choice <= 4) {
                if (trangThai == TrangThaiMuaVe::THANH_CONG)
                    std::cout << "[OK] Mua ve thanh cong!\n";
                else if (trangThai == TrangThaiMuaVe::LOI_GIOI_HAN) {
                    std::cout << "[ERROR] Da dat gioi han toi da 4 ve!\n";
                    break;
                }
                // LOI_GHE: chi bao loi, KHONG thoat
            }

        } catch (const BaseException& e) {
            std::cout << "[EXCEPTION] " << e.what() << "\n";
        }

    } while (true);

    std::cout << "Tong tien phai thanh toan: "
              << formatTien(kh.tongTien())
              << " VND\n";
}