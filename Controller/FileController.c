//
// Created by muzhou on 2020/12/27.
//

#include <stdio.h>
#include <stdlib.h>
#include "./FileController.h"

StatusPtr readDataFile(MetaPtr meta){
    LinkListPtr users = getUserRaw();
    LinkListPtr items = getItemRaw();
    if(meta == NULL || users == NULL || items == NULL)
        return newStatus(NULLPTR, L"");

    FILE *fid = fopen("data.bin", "rb");
    if(fid == NULL)
        return newStatus(FAILED, L"file open error");
    if(fread(meta, sizeof(MetaModel), 1, fid) == 0)
        return newStatus(FAILED, L"read error");
    UserPtr userData;
    for(int i = 0; i < meta->userNumber; i++){
        userData = malloc(sizeof(UserModel));
        if(fread(userData, sizeof(UserModel), 1, fid))
            LinkList_Insert(users, users->size, userData);
        else
            return newStatus(FAILED, L"read error");
    }

    ItemPtr itemData;
    for(int i = 0; i < meta->itemNumber; i++){
        itemData = malloc(sizeof(ItemModel));
        if(fread(itemData, sizeof(ItemModel), 1, fid))
            LinkList_Insert(items, items->size, itemData);
        else
            return newStatus(FAILED, L"read error");
    }

    fclose(fid);
    return newStatus(SUCCESS, L"");
}

StatusPtr writeDataFile(MetaPtr meta){
    LinkListPtr users = getUserRaw();
    LinkListPtr items = getItemRaw();
    if(meta == NULL || users == NULL || items == NULL)
        return newStatus(NULLPTR, L"");

    meta->userNumber = users->size;
    meta->itemNumber = items->size;

    FILE *fid = fopen("data.bin", "wb");
    if(fid == NULL)
        return newStatus(FAILED, L"file open error");
    fwrite(meta, sizeof(MetaModel), 1, fid);
    LinkListNodePtr user = users->head;
    UserPtr userData;
    while(user != NULL){
        userData = user->data;
        if(userData != NULL)
            fwrite(userData->raw, sizeof(UserModel), 1, fid);
        user = user->next;
    }

    LinkListNodePtr item = items->head;
    ItemPtr itemData;
    while(item != NULL){
        itemData = item->data;
        if(itemData != NULL)
            fwrite(itemData->raw, sizeof(ItemModel), 1, fid);
        item = item->next;
    }

    fclose(fid);
    return newStatus(SUCCESS, L"");
}