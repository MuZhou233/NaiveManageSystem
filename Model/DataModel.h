//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_DATAMODEL_H
#define KECHENGSHEJI_DATAMODEL_H

#include "../Base.h"
#include "./StatusModel.h"
#include <stdbool.h>

typedef struct LinkListNode LinkListNode;

struct LinkListNode {
    void* data;
    LinkListNode* next;
};

typedef struct {
    LinkListNode* head;
    u32 size;
} LinkList, *LinkListPtr;

typedef bool(*callback_LinkList)(void*, void*);

LinkList* Init_LinkList();
StatusPtr Insert_LinkList(LinkList* list, int pos, void * data);     // 指定位置插入
StatusPtr Remove_LinkList(LinkList* list, callback_LinkList, void* params);             // 删除指定位置的值
void* Find_LinkList(LinkList *list, callback_LinkList, void* params);
int Size_LinkList(LinkList* list);                              // 获取链表的长度
void* Front_LinkList(LinkList* list);                           // 返回第一个节点
StatusPtr FreeSpace_LinkList(LinkList* list);                        // 释放链表的内存

#endif //KECHENGSHEJI_DATAMODEL_H
