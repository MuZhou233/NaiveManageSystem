//
// Created by muzhou on 2020/12/27.
//

#ifndef KECHENGSHEJI_ITEMCONTROLLER_H
#define KECHENGSHEJI_ITEMCONTROLLER_H

#include "../Model/ItemModel.h"
#include "../Model/StatusModel.h"
#include "../Model/DataModel.h"

StatusPtr initItemController();
StatusPtr addItem(wchar_t[6][16]);
StatusPtr removeItem(u16);
StatusPtr searchItem(wchar_t*);
StatusPtr editItem(u16, wchar_t[6][16]);
LinkListPtr getItemRaw();

#endif //KECHENGSHEJI_ITEMCONTROLLER_H