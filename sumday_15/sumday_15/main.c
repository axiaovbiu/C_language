#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	char a[] = "123456789", *p = a;
	int i = 0;
	while (*p)
	{
		if (i % 2 == 0)
		{
			*p = '!';
		}
		i++;
		p++;
	}
	puts(a);
	return 0;
}*/
/*int main()
{
	char str[] = "ABCDEFG";
	char *p1, *p2;
	p1 = "abcd";
	p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);
	return 0;
}*/
/*int main()
{
	unsigned int a = 0xfffffff7;
	unsigned char i = (unsigned char)a;//��unsigned int ���͵�aǿת�� unsigned char ���ͣ���ʧ��6λ����Ϊ 000000f7
	char *b = (char *)&a;//(char *)ǿת��ת������a�ĵ�ַ����δ�ı�a�����ͣ����Դ�ӡ������䡣
	printf("%08x,%08x", i, *b);
	return 0;
}*/
/*int main()
{
	int j = 4;
	int i = j;
	for (; i <= 2 * j; i++)
	{
		switch (i / j)
		{
		case 0:
		case 1:
			printf("*");
			break;
		case 2:
			printf("#");
		}
	}
	return 0;
}*/
/*int main()
{
	int x = 1, y = 012;//c������0��ͷ�����ִ���8����
	int a = y;
	printf("%d", y*x++);
	return 0;
}*/
//�㷨�⣺�����ҵ���������м�λ��
typedef int SListDataType;
typedef struct SListNode{
	SListDataType data;
	struct SListNode *next;
}SList;
void SListInit(SList **pplist)
{
	(*pplist) = NULL;
}
SList *BuyData(SListDataType x)
{
	SList *cur = (SList *)malloc(sizeof(SList));
	cur->data = x;
	return cur;
}
void SListPushFront(SList **pplist,SListDataType x)
{
	SList *cur = BuyData(x);
	cur->next = *pplist;
	*pplist = cur;
}
void SListPrintf(SList *plist)
{
	SList *cur = plist;
	for (cur; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}
int Search(SList **pplist)//�����ָ�룬��ָ�룬��ָ����ٶ�����ָ���2��������ָ�������ʱ\
��ָ��պñ����������м䡣
{
	SList *fast = *pplist;
	SList *slow = *pplist;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}
int main()
{
	SList *test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPushFront(&test, 5);
	SListPrintf(test);
	printf("%d\n", Search(&test));
	return 0;
}