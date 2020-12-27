//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_USERMODEL_H
#define KECHENGSHEJI_USERMODEL_H

#include <wchar.h>
#include "../Base.h"

typedef union _UserModel{
    struct {
        u16 Uid;
        wchar_t Username[16];
        wchar_t Password[16];
    };
    char raw[0];
} UserModel, *UserPtr;

#endif //KECHENGSHEJI_USERMODEL_H
