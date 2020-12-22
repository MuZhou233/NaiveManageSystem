//
// Created by muzhou on 2020/12/20.
//

#include "DataModel.h"
#include <stdio.h>
#include <stdlib.h>

LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    list->head = (LinkListNode*)malloc(sizeof(LinkListNode));
    list->head->data = NULL;           // 头节点不保存数据
    list->head->next = NULL;

    return list;
}

void Insert_LinkList(LinkList* list, int pos, void * data)    // 指定位置插入
{
    if (list == NULL)
        return;
    if (data == NULL)
        return;

    if (pos<0 || pos > list->size)       // 不合法位置，插入到尾部
    {
        pos = list->size;
    }

    LinkListNode* newnode = (LinkListNode*)malloc(sizeof(LinkListNode));
    newnode->data = data;
    newnode->next = NULL;

    LinkListNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    list->size++;

}

void RemoveByPos_LinkList(LinkList* list, int pos)
{
    if (list == NULL)
        return;
    if (pos<0 || pos >= list->size)
    {
        return;
    }

    LinkListNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    LinkListNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    free(pDel);
    list->size--;
}

int Size_LinkList(LinkList* list)
{
    if (list == NULL)
        return -1;

    return list->size;
}

int Find_LinkList(LinkList *list, void* data)
{
    if (list == NULL)
        return -1;

    if (data == NULL)
        return -1;

    // 遍历查找
    LinkListNode* pCurrent = list->head->next;
    int i = 0;
    while (pCurrent)
    {
        if (pCurrent->data == data)
            break;
        i++;
        pCurrent = pCurrent->next;
    }
    return i;
}

void* Front_LinkList(LinkList* list)
{
    if (list == NULL)
        return NULL;
    return list->head->next->data;
}

void FreeSpace_LinkList(LinkList* list)
{
    if (list == NULL)
        return;
    LinkListNode* pCurrent = list->head;
    while (pCurrent)
    {
        LinkListNode* pNext = pCurrent->next;       // 缓存下一个结点
        free(pCurrent);
        pCurrent = pNext;
    }
    list->size = 0;
    free(list);
}