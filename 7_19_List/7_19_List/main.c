#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushFront(&list, 5);
	ListPopBack(&list);
	ListRemove(&list, 5);
	ListPrint(&list);
	ListDestory(&list);
	return 0;
}