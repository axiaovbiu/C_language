#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
void SListInit(SList* plist)
{
	plist->next = NULL;
	plist->data = 0;
}
void SListDestory(SList **pplist)
{
	while (*pplist)
	{
		SListPopFront(*pplist);
	}
	free(*pplist);
}
SList* BuySList(SLTDataType x)
{
	SList *cur = (SList *)malloc(sizeof(SList));
	cur->data = x;
	return cur;
}
void SListPushFront(SList **pplist, SLTDataType x)
{
	SList *tmp = BuySList(x);
	tmp->next = *pplist;
	*pplist = tmp;
	return;
}
void SListPopFront(SList **pplist)
{
	SList *tmp;
	if (*pplist == NULL)
	{
		return -1;
	}
	tmp = (*pplist)->next;
	free(*pplist);
	*pplist = tmp;
	return;
}
SList* SListFind(SList *plist, SLTDataType x)
{
	SList *cur;
	for (cur = plist; cur; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SList *pos, SLTDataType x)//在pos结点后面插入一个元素
{
	SList *cur = BuySList(x);
	cur->next = pos->next;
	pos->next = cur;
	return;
}
void SListEraseAfter(SList *pos)//删除pos结点后面的一个元素
{
	SList *tmp = pos->next;//用tmp记录要删除的元素，以便释放
	if (!pos)//如果pos结点是空的，则返回NULL
	{
		return NULL;
	}
	pos->next = tmp->next;
	free(tmp);
	return;
}
void SListRemove(SList **pplist, SLTDataType x)//删除链表中第一次出现的x元素
{
	SList *cur = *pplist;
	if (!*pplist)
	{
		return;
	}
	if ((*pplist)->data == x)//如果x第一次出现的位置在头结点上，则直接头删
	{
		SListPopFront(pplist);
		return;
	}
	for (cur; cur->next; cur = cur->next)
	{
		if (cur->next->data == x)//找到x第一次出现的前一个位置，进行后删
		{
			SListEraseAfter(cur);
		}
		return;
	}
}
void SListRemoveAll(SList **pplist, SLTDataType x)
{
	SList *cur = *pplist;
	while (cur && (cur->data == x))//每当头结点为x，则删除，直到头结点不为x
	{
		SListPopFront(pplist);
	}
	for (cur; cur->next;)//其余结点利用后删删除，但当出现多个连续x时，后删会跳过第一个x的下下一个x，导致没有完全删除
	{
		if (cur->next->data == x)//如果cur的下一结点为x则删除cur的next，继续判断cur的下一个节点是否为x
		{
			SListEraseAfter(cur);
		}
		else
		{
			cur = cur->next;//当删除完cur后面的所有x后，cur向后移动。
		}
	}
}
void SListPrint(SList* plist)
{
	SList *cur = plist;
	for (cur; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
	return;
}