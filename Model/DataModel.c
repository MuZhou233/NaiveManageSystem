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

StatusPtr Insert_LinkList(LinkList* list, int pos, void * data)    // 指定位置插入
{
    if (list == NULL || data == NULL)
        return newStatus(NULLPTR, L"");

    if (pos<0 || pos > list->size)       // 不合法位置，插入到尾部
        pos = list->size;

    LinkListNode* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    newNode->data = data;
    newNode->next = NULL;

    LinkListNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++)
        pCurrent = pCurrent->next;

    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    list->size++;
    return newStatus(SUCCESS, L"");
}

StatusPtr Remove_LinkList(LinkList* list, callback_LinkList func, void* params)
{
    if (list == NULL)
        return newStatus(NULLPTR, L"");

    LinkListNode* pCurrent = list->head;
    while (pCurrent)
    {
        if (func(pCurrent->next->data, params))
            break;
        pCurrent = pCurrent->next;
    }

    LinkListNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    free(pDel);
    list->size--;
    return newStatus(SUCCESS, L"");
}

int Size_LinkList(LinkList* list)
{
    if (list == NULL)
        return -1;

    return list->size;
}

void* Find_LinkList(LinkList *list, callback_LinkList func, void* params)
{
    if (list == NULL)
        return newStatus(NULLPTR, L"");

    // 遍历查找
    LinkListNode* pCurrent = list->head;
    while (pCurrent)
    {
        if (func(pCurrent->data, params))
            return pCurrent->data;
        pCurrent = pCurrent->next;
    }
    return NULL;
}

void* Front_LinkList(LinkList* list)
{
    if (list == NULL)
        return NULL;
    return list->head->next->data;
}

StatusPtr FreeSpace_LinkList(LinkList* list)
{
    if(list->head != NULL){
        LinkListNode* pCurrent = list->head;
        while (pCurrent->next != NULL)
        {
            LinkListNode* pNext = pCurrent->next;       // 缓存下一个结点
            free(pCurrent);
            pCurrent = pNext;
        }
        free(pCurrent);
    }
    free(list);
    return newStatus(SUCCESS, L"");
}