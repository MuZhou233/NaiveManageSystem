//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_METAMODEL_H
#define KECHENGSHEJI_METAMODEL_H

#include "../Base.h"
#include <wchar.h>

typedef union {
    struct {
        u8 userNumber;
        u32 itemNumber;
        wchar_t itemMeta[6][8];
    };
    char raw[0];
} MetaModel, *MetaPtr;

MetaPtr newMeta(u8, u32);

#endif //KECHENGSHEJI_METAMODEL_H
