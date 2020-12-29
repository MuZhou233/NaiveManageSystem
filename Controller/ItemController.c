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

StatusPtr addItem(wchar_t data[6][16]){
    if(!logged())
        return newStatus(FAILED, L"user not logged");
    ItemPtr item = malloc(sizeof(ItemModel));
    item->Iid = Items->size+1;
    memcpy(item->data, data, sizeof(wchar_t)*6*16);
    return LinkList_Insert(Items, Items->size, item);
}

bool removeItem_callback(void* _data, void* _uid){
    if(_data == NULL || _uid == NULL)
        return false;
    UserPtr data = _data;
    u16* uid = _uid;
    return data->uid == *uid;
}

StatusPtr removeItem(u32 iid){
    return LinkList_Remove(Items, removeItem_callback, &iid);
}

bool searchItemByContent_callback(void* _data, void* _content){
    if(_data == NULL || _content == NULL)
        return false;
    ItemPtr data = _data;
    wchar_t* content = _content;
    for(int i = 0; i < 6; i++){
        if(wcsstr(data->data[i], content) != NULL)
            return true;
    }
    return false;
}

ItemPtr searchItemByContent(wchar_t* content){
    if(content == NULL)
        return NULL;
    return LinkList_Find(Items, searchItemByContent_callback, content);
}

bool searchItemById_callback(void* _data, void* _iid){
    if(_data == NULL || _iid == NULL)
        return false;
    ItemPtr data = _data;
    u32* iid = _iid;
    return data->Iid == *iid;
}

ItemPtr searchItemById(u32 iid){
    return LinkList_Find(Items, searchItemById_callback, &iid);
}

StatusPtr editItem(u32 iid, wchar_t* data){
    if(data == NULL)
        return newStatus(NULLPTR, L"");
    ItemPtr item = searchItemById(iid);
    if(item == NULL)
        return newStatus(FAILED, L"item not found");
    memcpy(item->data, data, sizeof(wchar_t)*6*16);
    return newStatus(SUCCESS, L"");
}

LinkListPtr getItemRaw(){
    return Items;
}
