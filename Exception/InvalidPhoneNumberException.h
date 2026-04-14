//
// Created by PC on 4/14/2026.
//

#ifndef VCT_PACIFIC_STAGE_1_INVALIDPHONENUMBEREXCEPTION_H
#define VCT_PACIFIC_STAGE_1_INVALIDPHONENUMBEREXCEPTION_H

#include "BaseException.h"

/*
 * InvalidPhoneNumberException
 * ---------------------------
 * Phát sinh khi số điện thoại:
 *  - Không đúng 10 chữ số
 *  - Hoặc chứa ký tự không phải số
 */
class InvalidPhoneNumberException : public BaseException {
public:
    explicit InvalidPhoneNumberException(const std::string& phone)
        : BaseException(
            "So dien thoai khong hop le: " + phone +
            ". So dien thoai phai gom DUNG 10 chu so."
          ) {}
};

#endif //VCT_PACIFIC_STAGE_1_INVALIDPHONENUMBEREXCEPTION_H