//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_ITEMMODEL_H
#define KECHENGSHEJI_ITEMMODEL_H

#include <wchar.h>
#include "../Base.h"

typedef union {
    struct {
        u32 Iid;
        wchar_t metas[6][16];
    };
    char raw[0];
} ItemModel, *ItemPtr;

#endif //KECHENGSHEJI_ITEMMODEL_H
