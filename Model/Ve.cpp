//
// Created by PC on 4/9/2026.
//

#include "../Model/Ve.h"
Ve::Ve(const std::string& ngay,
       const std::string& zone,
       const std::string& seat,
       double gia)
    : ngaySuDung(ngay),
      khuVucGhe(zone),
      soGhe(seat),
      giaCoBan(gia) {}

std::string Ve::getNgaySuDung() const {
    return ngaySuDung;
}

std::string Ve::getKhuVuc() const {
    return khuVucGhe;
}

std::string Ve::getSoGhe() const {
    return soGhe;
}

double Ve::tinhGia() const {
    return giaCoBan * tinhHeSoGia();
}

