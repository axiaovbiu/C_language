#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int fun(int a, int b)
{
	if (a > b)
		return(a + b);
	else
		return(a - b);
}
int main()
{
	int x = 3, y = 8, z = 6, r;
	r = fun(fun(x, y), 2 * z);
	printf("%d\n", r);
	return 0;
}*/
/*int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return(a);
}
int main()
{
	int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf("%d\n", k);
	return 0;
}*/
/*int x = 3;
void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d", x);
	return;
}
int main()
{
	int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}
	return 0;
}*/
//算法题：逆置单链表（无头）
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;

}SList;
void SListInit(SList **pplist)
{
	(*pplist) = NULL;
}
SList *BuyList(SListDataType x)
{
	SList *cur = (SList *)malloc(sizeof(SList));
	cur->data = x;
	return cur;
}
void PushFront(SList **pplist, SListDataType x)
{
	SList *cur = BuyList(x);
	cur->next = *pplist;
	(*pplist) = cur;
}
void SListPrint(SList *plist)
{
	SList *cur = plist;
	for (cur; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL");
}
void SListReverse1(SList **pplist)
{
	SList *oldhead = *pplist;
	SList *head = *pplist;
	SList *tmp = head->next;
	while (tmp)
	{
		oldhead->next = tmp->next;
		tmp->next = head;
		head = tmp;
		tmp = oldhead->next;
	}
	*pplist = head;
	return;
}
void SListReverse2(SList **pplist)
{
	SList *pre = *pplist;
	SList *cur = pre->next;
	SList *next = cur;
	pre->next = NULL;
	while (next)
	{
		next = next->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	(*pplist) = pre;
	return;
}
int main()
{
	SList *test;
	SListInit(&test);
	PushFront(&test, 1);
	PushFront(&test, 2);
	PushFront(&test, 3);
	PushFront(&test, 4);
	PushFront(&test, 5);
	PushFront(&test, 6);
	SListReverse2(&test);
	SListPrint(test);
	return 0;
}