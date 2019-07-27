#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlis.h"
int main()
{
	SeqList cur;
	SeqListInit(&cur,2);
	SeqListPushBack(&cur, 1);
	SeqListPushBack(&cur, 2);
	SeqListPushBack(&cur, 3);
	SeqListPushBack(&cur, 4);
	SeqListPushFront(&cur,5);
	SeqListPushFront(&cur, 6);
	SeqListPushFront(&cur, 6);
	SeqListPushFront(&cur, 6);
	SeqListPushFront(&cur, 6);
	/*SeqListPopBack(&cur);
	SeqListPopFront(&cur);
	SeqListInsert(&cur, 2, 9);
	SeqListErase(&cur, 2);
	SeqListRemove(&cur,5);
	SeqListModify(&cur, 1, 5);*/
	//SeqListBubbleSort(&cur);
	//SeqListRemoveAll(&cur, 6);
	SeqListPrint(&cur);
	return 0;
}
