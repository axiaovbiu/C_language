#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
void SListInit(SList* plist)
{
	plist->next = NULL;
	plist->data = 0;
}
void SListDestory(SList **pplist)
{
	while (*pplist)
	{
		SListPopFront(*pplist);
	}
	free(*pplist);
}
SList* BuySList(SLTDataType x)
{
	SList *cur = (SList *)malloc(sizeof(SList));
	cur->data = x;
	return cur;
}
void SListPushFront(SList **pplist, SLTDataType x)
{
	SList *tmp = BuySList(x);
	tmp->next = *pplist;
	*pplist = tmp;
	return;
}
void SListPopFront(SList **pplist)
{
	SList *tmp;
	if (*pplist == NULL)
	{
		return -1;
	}
	tmp = (*pplist)->next;
	free(*pplist);
	*pplist = tmp;
	return;
}
SList* SListFind(SList *plist, SLTDataType x)
{
	SList *cur;
	for (cur = plist; cur; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SList *pos, SLTDataType x)//��pos���������һ��Ԫ��
{
	SList *cur = BuySList(x);
	cur->next = pos->next;
	pos->next = cur;
	return;
}
void SListEraseAfter(SList *pos)//ɾ��pos�������һ��Ԫ��
{
	SList *tmp = pos->next;//��tmp��¼Ҫɾ����Ԫ�أ��Ա��ͷ�
	if (!pos)//���pos����ǿյģ��򷵻�NULL
	{
		return NULL;
	}
	pos->next = tmp->next;
	free(tmp);
	return;
}
void SListRemove(SList **pplist, SLTDataType x)//ɾ�������е�һ�γ��ֵ�xԪ��
{
	SList *cur = *pplist;
	if (!*pplist)
	{
		return;
	}
	if ((*pplist)->data == x)//���x��һ�γ��ֵ�λ����ͷ����ϣ���ֱ��ͷɾ
	{
		SListPopFront(pplist);
		return;
	}
	for (cur; cur->next; cur = cur->next)
	{
		if (cur->next->data == x)//�ҵ�x��һ�γ��ֵ�ǰһ��λ�ã����к�ɾ
		{
			SListEraseAfter(cur);
		}
		return;
	}
}
void SListRemoveAll(SList **pplist, SLTDataType x)
{
	SList *cur = *pplist;
	while (cur && (cur->data == x))//ÿ��ͷ���Ϊx����ɾ����ֱ��ͷ��㲻Ϊx
	{
		SListPopFront(pplist);
	}
	for (cur; cur->next;)//���������ú�ɾɾ�����������ֶ������xʱ����ɾ��������һ��x������һ��x������û����ȫɾ��
	{
		if (cur->next->data == x)//���cur����һ���Ϊx��ɾ��cur��next�������ж�cur����һ���ڵ��Ƿ�Ϊx
		{
			SListEraseAfter(cur);
		}
		else
		{
			cur = cur->next;//��ɾ����cur���������x��cur����ƶ���
		}
	}
}
void SListPrint(SList* plist)
{
	SList *cur = plist;
	for (cur; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
	return;
}