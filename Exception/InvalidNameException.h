//
// Created by PC on 4/14/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_INVALIDNAMEEXCEPTION_H
#define VCT_PACIFIC_STAGE_1_INVALIDNAMEEXCEPTION_H

#include "BaseException.h"

/*
 * InvalidNameException
 * --------------------
 * Phát sinh khi tên khách hàng:
 *  - Có ký tự đặc biệt
 *  - Hoặc có chữ số
 */
class InvalidNameException : public BaseException {
public:
    explicit InvalidNameException(const std::string& name)
        : BaseException(
            "Ten khach hang khong hop le: " + name +
            ". Ten chi duoc chua CHU CAI va KHOANG TRANG."
          ) {}
};

#endif //VCT_PACIFIC_STAGE_1_INVALIDNAMEEXCEPTION_H