//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_ITEMMODEL_H
#define KECHENGSHEJI_ITEMMODEL_H

#include<wchar.h>

typedef union _ItemModel{
    struct {
        char Iid;
        wchar_t name[16];
        int number;
        int price;
    };
    char raw[0];
} ItemModel, *ItemPtr;

#endif //KECHENGSHEJI_ITEMMODEL_H
