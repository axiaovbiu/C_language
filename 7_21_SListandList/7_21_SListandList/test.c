#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
void SListNodeInit(SListNode **pphead)
{
	*pphead = NULL;
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode *tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->data = x;
	return tmp;
}

void SListPushFront(SListNode **pphead, SLTDataType x)
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
	return;
}
void SListNodePrintf(SListNode *phead)
{
	SListNode *tmp = phead;
	for (tmp; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}
void SListReverse1(SListNode **pphead)
{
	SListNode *head = *pphead;
	SListNode *tmp = head->next;
	SListNode *oldhead = *pphead;
	while (tmp)
	{
		oldhead->next = tmp->next;
		tmp->next = head;
		head = tmp;
		tmp = oldhead->next;
	}
	*pphead = head;
}
void SListReverse2(SListNode **pphead)
{
	SListNode *pre = *pphead;
	SListNode *cur = pre->next;
	SListNode *next = cur;
	pre->next = NULL;
	while (next)
	{
		next = next->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	*pphead = pre;
}