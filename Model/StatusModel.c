//
// Created by muzhou on 2020/12/24.
//

#include "./StatusModel.h"
#include <stdlib.h>

StatusPtr newStatus(STAT stat, wchar_t* msg){
    StatusPtr ret =  malloc(sizeof(StatusModel));
    ret->stat = stat;
    ret->msg = (wchar_t*)malloc(wcslen(msg));
    wcscpy(ret->msg, msg);
    return ret;
}
