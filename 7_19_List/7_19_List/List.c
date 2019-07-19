#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}
void ListInsertAfter(ListNode *pos, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;
	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
	cur->_data = x;
}
void LsitInsertFront(ListNode *pos, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;
	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
	cur->_data = x;

}
void ListPushBack(List* plist, LTDataType x)
{
	LsitInsertFront(plist->_head, x);
}
void ListPopBack(List *plist, LTDataType x)
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List *plist, LTDataType x)
{
	ListInsertAfter(plist->_head,x);
}
void ListPopFront(List *plist)
{
	ListErase(plist->_head->_next);
}
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode *tmp = plist->_head->_next;
	for (tmp; tmp != plist->_head; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
void ListRemove(List* plist, LTDataType x)
{
	ListNode *tmp = ListFind(plist, x);
	if (tmp)
	{
		ListErase(tmp);
	}
}
void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListPrint(List* plist)
{
	ListNode *cur;
	printf("head->");
	for (cur = plist->_head->_next; cur !=plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("head");
	return;
}