#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SLIST_H_
#define _SLIST_H_
#include<stdio.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;
void SListInit(SListNode* phead);
void SListDestory(SListNode* phead);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode* phead, SLTDataType x);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** head, SLTDataType x);
void SListPrint(SListNode* phead);
void TestSList();
#endif