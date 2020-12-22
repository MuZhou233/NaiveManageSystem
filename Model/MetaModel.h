//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_METAMODEL_H
#define KECHENGSHEJI_METAMODEL_H

#define MaxUserNumber sizeof(char)
#define MaxItemNumber sizeof(int)

typedef struct _MetaModel{
    char UserNumber;
    int ItemNumber;
} MetaModel, *MetaPtr;

#endif //KECHENGSHEJI_METAMODEL_H
