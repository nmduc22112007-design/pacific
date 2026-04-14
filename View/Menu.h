//
// Created by PC on 4/9/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_MENU_H
#define VCT_PACIFIC_STAGE_1_MENU_H
#include "../Model/KhachHang.h"
#include "../Control/TicketManager.h"
class Menu {
public:
    static void hienThiMenu();
    static void xuLyMuaVe(KhachHang& kh);
    static void xuLyMenu(TicketManager& manager);
};


#endif //VCT_PACIFIC_STAGE_1_MENU_H