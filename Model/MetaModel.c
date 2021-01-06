//
// Created by 小麦 on 2021/1/6.
//

#include "./MetaModel.h"
#include <stdlib.h>

MetaPtr newMeta(u8 userNumber, u32 itemNumber){
    MetaPtr res = malloc(sizeof(MetaModel));
    if(res == NULL) return NULL;
    res->userNumber = userNumber;
    res->itemNumber = itemNumber;
    wcscpy(res->itemMeta[2], L"封装:");
    wcscpy(res->itemMeta[3], L"厂家:");
    wcscpy(res->itemMeta[4], L"单价:");
    wcscpy(res->itemMeta[5], L"库存:");
    return res;
}