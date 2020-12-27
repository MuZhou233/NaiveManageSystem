//
// Created by muzhou on 2020/12/27.
//

#include "./FileController.h"

StatusPtr readDataFile(MetaPtr meta){
    LinkListPtr user = getUserRaw();
    return newStatus(SUCCESS, L"");
}

StatusPtr writeDataFile(MetaPtr meta){
    LinkListPtr user = getUserRaw();
    return newStatus(SUCCESS, L"");
}