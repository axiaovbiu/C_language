#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
int main()
{
	SList *test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 1);
	SListPushFront(&test, 1);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPushFront(&test, 4);
	SListPushFront(&test, 4);
	/*SListPopFront(&test);
	SListPopFront(&test);
	SListPopFront(&test);
	SListPopFront(&test);*/
	/*SListInsertAfter(SListFind(test,1), 5);
	SListEraseAfter(SListFind(test, 4));*/
	//SListRemove(&test, 1);
	//SListRemove(&test, 4);
	SListRemoveAll(&test, 1);
	SListPrint(test);
	//SListDestory(&test);
	return 0;
}