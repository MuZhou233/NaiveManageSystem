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
        struct _ItemMeta {
            wchar_t* p1;
            wchar_t* p2;
            wchar_t* p3;
            wchar_t* p4;
            wchar_t* p5;
            wchar_t* p6;
        } ItemMeta ;
    };
    char raw[0];
} MetaModel, *MetaPtr;

#endif //KECHENGSHEJI_METAMODEL_H
