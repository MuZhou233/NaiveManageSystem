//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_METAMODEL_H
#define KECHENGSHEJI_METAMODEL_H

#define MaxUserNumber 1<<(4*sizeof(char))
#define MaxItemNumber 1<<(4*sizeof(int))

typedef union _MetaModel{
    struct {
        char UserNumber;
        int ItemNumber;
    }
    char raw[0];
} MetaModel, *MetaPtr;

#endif //KECHENGSHEJI_METAMODEL_H
