#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlis.h"
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->capicity = capacity;
	psl->array = (SeqList *)calloc(psl->capicity,sizeof(SeqList));
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	if (psl->array)
	{
		psl->array = NULL;
		psl->capicity = 0;
		psl->size = 0;
		free(psl->array);
	}
}
void CheckCapacity(SeqList* psl)
{
	if (psl->capicity == psl->size)
	{
		psl->capicity *= 2;
		psl->array = (SeqList *)realloc(psl->array, sizeof(SeqList)* psl->capicity);
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i; i--)
	{
		psl->array[i] = psl->array[i-1];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i+1];
	}
	psl->size--;
	return;
}
int SeqListFind(SeqList* psl, SLDataType x)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i >= pos; i--)
		{
			psl->array[i] = psl->array[i-1];
		}
	psl->array[pos - 1] = x;
	psl->size++;
	return;
	
}
void SeqListErase(SeqList* psl, size_t pos)
{
	int i;
	for (i = pos; i < psl->size; i++)
		{
			psl->array[i - 1] = psl->array[i];
		}
	psl->size--;
	return;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	int i;
	i = SeqListFind(psl, x);
	if (i != -1)
	{
	SeqListErase(psl, i);
	return;
	}
	printf("Not Find\n");
	return;
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->array[pos - 1] = x;
	return;
}
void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
	return;
}