#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListInit(SListNode** pphead)//��ʼ��
{
	*pphead = NULL;
}
SListNode* BuySListNode(SLTDataType x)//�������
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;
	p->next = NULL;
	return p;
}
void SListPushFront(SListNode** pphead, SLTDataType x)//ͷ��
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = (*pphead);
	*pphead = tmp;
	return;
}
void SListPopFront(SListNode** pphead)//ͷɾ
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	(*pphead) = tmp;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//��壨��pos�������ֵΪx�Ľ�㣩
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
	return;
}
void SListEraseAfter(SListNode* pos)//ɾ��pos����Ľ��
{
	SListNode *tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
SListNode* SListFind(SListNode* phead, SLTDataType x)//����ֵΪx�Ľ��
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
void SListRemove(SListNode** pphead, SLTDataType x)//ɾ��ֵΪx�ĵ�һ�����
{
	SListNode* tmp = *pphead;
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListDestory(SListNode** pphead)//��������
{
	if (*pphead == NULL)
	{
		return;
	}
	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}
void SListPrint(SListNode* phead)//��ӡ����
{
	SListNode* tmp = phead;
	for (tmp; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
	return;
}