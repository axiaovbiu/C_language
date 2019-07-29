#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SLIST_H_
#define _SLIST_H_
#include<stdio.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode *next;
}SList;

void SListInit(SList *plist);
void SListDestory(SList *plist);
SList *BuySListNode(SLTDataType x);
void SListPushFront(SList **pplist, SLTDataType x);
void SListPopFront(SList **pplist);
SList *SListFind(SList *plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SList *pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SList *pos);
void SListRemove(SList **pplist, SLTDataType x);
void SListRemoveAll(SList **pplist, SLTDataType x);
void SListPrint(SList *plist);
#endif