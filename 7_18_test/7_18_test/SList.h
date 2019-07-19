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
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** head, SLTDataType x);
void SListPrint(SListNode* phead);
void TestSList();
#endif