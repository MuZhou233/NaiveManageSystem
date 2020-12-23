//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_STATUSMODEL_H
#define KECHENGSHEJI_STATUSMODEL_H

typedef union _StatusModel{
    struct {
        enum stat {
            SUCCESS = 1,
            FAILED,
            UNDEFINED,
            UNKOWNERROR
        };
    };
    char raw[0];
} StatusModel, *StatusPtr;

StatusPtr newStatus(stat);

#endif //KECHENGSHEJI_STATUSMODEL_H
