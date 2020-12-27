//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_DATAMODEL_H
#define KECHENGSHEJI_DATAMODEL_H

#include "../Base.h"
#include "./StatusModel.h"
#include <stdbool.h>

typedef struct LinkListNode LinkListNode, *LinkListNodePtr;

struct LinkListNode {
    void* data;
    LinkListNode* next;
};

typedef struct {
    LinkListNode* head;
    u32 size;
} LinkList, *LinkListPtr;

typedef bool(*LinkList_Callback)(void*, void*);

LinkList* LinkList_Init();
StatusPtr LinkList_Insert(LinkList* list, int pos, void * data);     // 指定位置插入
StatusPtr LinkList_Remove(LinkList* list, LinkList_Callback, void* params);             // 删除指定位置的值
void* LinkList_Find(LinkList *list, LinkList_Callback, void* params);
void* LinkList_FindNext(LinkListNode *list, LinkList_Callback, void* params);
int LinkList_Size(LinkList* list);                              // 获取链表的长度
StatusPtr LinkList_Free(LinkList* list);                        // 释放链表的内存

#endif //KECHENGSHEJI_DATAMODEL_H
