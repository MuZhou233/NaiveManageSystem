//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_DATAMODEL_H
#define KECHENGSHEJI_DATAMODEL_H

typedef struct _LinkListNode LinkListNode;

struct _LinkListNode {
    void* data;
    LinkListNode* next;
};

typedef struct _LinkList {
    LinkListNode* head;
    int size;
} LinkList;

void Insert_LinkList(LinkList* list, int pos, void * data);     // 指定位置插入
void RemoveByPos_LinkList(LinkList* list, int pos);             // 删除指定位置的值
int Size_LinkList(LinkList* list);                              // 获取链表的长度
void* Front_LinkList(LinkList* list);                           // 返回第一个节点
void FreeSpace_LinkList(LinkList* list);                        // 释放链表的内存

#endif //KECHENGSHEJI_DATAMODEL_H
