#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define CIR(r) r*r
/*int Change(int *px)
{
	int y = 8;
	y = y - *px;
	px = &y;
	return 0;
}
int main()
{
	int xx = 3;
	int *py = &xx;
	Change(py);
	printf("%d", *py);
	return 0;
}*/
/*int main()
{
	char arr[2][4];
	char a = -27;
	strcpy((char *)arr, "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';
	printf("%s\n", arr);
	return 0;
}*/
/*int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x &(x - 1);
	}
	return count;
}
int main()
{
	printf("fun(2017) = %d\n", fun(2019));
	return 0;
}*/
/*int main()
{
	int a = 1;
	int b = 2;
	int t;
	t = CIR(a + b);
	printf("%d\n", t);
	return 0;
}*/
/*unsigned long d = 0;
void GlobalInit(unsigned long d)
{
	d = 0x01;
	return;
}
void Test()
{
	GlobalInit(d);
	printf("%lu", d);
	return;
}
int main()
{
	Test(d);
	return 0;
}*/

//算法题：有一张单链表，求倒数第k个结点
typedef int SListDataType;
typedef struct st
{
	SListDataType data;
	struct st *next;
}SList;
void SListInit(SList **pplist)
{
	(*pplist) = NULL;
}
SList *BuySList(SListDataType x)
{
	SList *cur = (SList *)malloc(sizeof(SList));
	cur->data = x;
	return cur;
}
void PushFront(SList **pplist,SListDataType x)
{
	SList *cur = BuySList(x);
	cur->next = *pplist;
	*pplist = cur;
	return;
}
void SListPrint(SList *plist)
{
	SList *cur;
	for (cur = plist; cur; cur = cur->next)
	{
		printf("%d-> ", cur->data);
	}
	printf("NULL\n");
}
SList *Searchr(SList *plist, SListDataType x)
{
	SList *fast = plist;
	SList *slow = plist;
	while (x&&fast)
	{
		fast = fast->next;
		x--;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
	SList *ret;
	SList *test;
	SListInit(&test);
	PushFront(&test, 1);
	PushFront(&test, 2);
	PushFront(&test, 3);
	PushFront(&test, 4);
	PushFront(&test, 8);
	SListPrint(test);
	ret = Searchr(test,1);
	printf("%d\n", ret->data);
	return 0;
}