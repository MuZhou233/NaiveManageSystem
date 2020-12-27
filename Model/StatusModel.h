//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_STATUSMODEL_H
#define KECHENGSHEJI_STATUSMODEL_H

#include <wchar.h>

typedef enum {
    SUCCESS = 0,
    FAILED,
    NULLPTR,
    UNKNOWN
} STAT;

typedef union {
    struct {
        STAT stat;
        wchar_t* msg;
    };
    char raw[0];
} StatusModel, *StatusPtr;

StatusPtr newStatus(STAT, wchar_t*);

#endif //KECHENGSHEJI_STATUSMODEL_H
