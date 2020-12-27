//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_USERMODEL_H
#define KECHENGSHEJI_USERMODEL_H

#include <wchar.h>
#include "../Base.h"

typedef union _UserModel{
    struct {
        u16 uid;
        wchar_t username[16];
        wchar_t password[16];
    };
    char raw[0];
} UserModel, *UserPtr;

#endif //KECHENGSHEJI_USERMODEL_H
