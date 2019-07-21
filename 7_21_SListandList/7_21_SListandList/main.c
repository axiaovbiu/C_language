#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int main()
{
	SListNode *head;
	SListNodeInit(&head);
	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);
	//SListReverse1(&head);
	SListReverse2(&head);
	SListNodePrintf(head);
	return 0;
}