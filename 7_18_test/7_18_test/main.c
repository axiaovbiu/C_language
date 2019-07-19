#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

int main()
{

	SListNode *head;
	SListInit(&head);
	SListPushFront(&head,1);
	SListPushFront(&head,2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	SListInsertAfter(SListFind(head, 4), 7);
	SListRemove(&head, 4);
	SListPopFront(&head);
	SListEraseAfter(SListFind(head,4));
	SListDestory(&head);
	SListPrint(head);
	system("pause");
	return 0;
}