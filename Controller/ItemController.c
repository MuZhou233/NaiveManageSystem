//
// Created by muzhou on 2020/12/27.
//

#include "./ItemController.h"
#include "./UserController.h"
#include <stdlib.h>
#include <string.h>

LinkListPtr Items;

StatusPtr initItemController(){
   Items = LinkList_Init();
   return newStatus(SUCCESS, L"");
}

StatusPtr addItem(wchar_t items[6][16]){
    if(!logged())
        return newStatus(FAILED, L"user not logged");
    ItemPtr item = malloc(sizeof(ItemModel));
    item->Iid = Items->size+1;
    memcpy(item->data, items, sizeof(wchar_t)*6*16);
    return LinkList_Insert(Items, Items->size, item);
}

bool removeItem_callback(void* _data, void* _uid){
    if(_data == NULL || _uid == NULL)
        return false;
    UserPtr data = _data;
    u16* uid = _uid;
    return data->uid == *uid;
}

StatusPtr removeUser(u16 uid){
    if(loggedUser == NULL || loggedUser->uid != uid)
        return newStatus(NULLPTR, L"");
    return LinkList_Remove(Users, removeUser_callback, &uid);
}

bool searchUser_callback(void* _data, void* _username){
    if(_data == NULL || _username == NULL)
        return false;
    UserPtr data = _data;
    wchar_t* username = _username;
    return wcscmp(data->username, username);
}

UserPtr searchUser(wchar_t* username){
    if(username == NULL)
        return NULL;
    return LinkList_Find(Users, searchUser_callback, username);
}

StatusPtr editUser(wchar_t* username, wchar_t* password){
    if(username == NULL || password == NULL)
        return newStatus(NULLPTR, L"");
    wcscpy(loggedUser->username, username);
    wcscpy(loggedUser->password, password);
    return newStatus(SUCCESS, L"");
}

LinkListPtr getItemRaw(){
    return Items;
}
