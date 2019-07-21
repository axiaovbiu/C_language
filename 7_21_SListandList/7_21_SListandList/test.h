#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _TEST_H_
#define _TEST_H_
#include<stdio.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;
SListNode* BuySListNode(SLTDataType x);
void SListNodeInit(SListNode **pphead);
void SListPushFront(SListNode **pphead, SLTDataType x);
void SListReverse1(SListNode **pphead);
void SListReverse2(SListNode **pphead);
void SListPrintf(SListNode *phead);
#endif 