#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListInit(SListNode** pphead)//初始化
{
	*pphead = NULL;
}
SListNode* BuySListNode(SLTDataType x)//创建结点
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;
	p->next = NULL;
	return p;
}
void SListPushFront(SListNode** pphead, SLTDataType x)//头插
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = (*pphead);
	*pphead = tmp;
	return;
}
void SListPopFront(SListNode** pphead)//头删
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	(*pphead) = tmp;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//后插（在pos结点后插入值为x的结点）
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
	return;
}
void SListEraseAfter(SListNode* pos)//删除pos结点后的结点
{
	SListNode *tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
SListNode* SListFind(SListNode* phead, SLTDataType x)//查找值为x的结点
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
void SListRemove(SListNode** pphead, SLTDataType x)//删除值为x的第一个结点
{
	SListNode* tmp = *pphead;
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListDestory(SListNode** pphead)//销毁链表
{
	if (*pphead == NULL)
	{
		return;
	}
	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}
void SListPrint(SListNode* phead)//打印链表
{
	SListNode* tmp = phead;
	for (tmp; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
	return;
}