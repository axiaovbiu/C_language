#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void DownAdjust(Heap *hp, int n)//构建大根
{
	int cur = n;
	while (cur * 2 +1 < hp->size)
	{
		if (hp->data[cur] < hp->data[cur * 2 + 1])
		{
			if (cur * 2 + 2 >= hp->size || hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])
			{
				Swap(&hp->data[cur], &hp->data[cur * 2 + 1]);
				cur = cur * 2 + 1;
			}
			else
			{
				Swap(&hp->data[cur], &hp->data[cur * 2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if (cur * 2 +2 <= hp->size && hp->data[cur] < hp->data[cur * 2 +2])
		{
			Swap(&hp->data[cur], &hp->data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap  *hp, HPDataType *a, int n)
{
	int i;
	hp->capacity = MAXSIZE > n ? MAXSIZE : n;
	hp->size = n;
	hp->data = (HPDataType *)malloc(sizeof(HPDataType)* hp->capacity);
	memcpy(hp->data, a, sizeof(HPDataType)* n);

	for (i = n/2 - 1; i >= 0; i--)
	{
		DownAdjust(hp, i);
	}
}
void HeapDestory(Heap *hp)
{
	if (hp->data)
	{
		free(hp->data);
		hp->data = NULL;
		hp->size = hp->capacity = 0;
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->size;
	if (hp->capacity == hp->size)
	{
		hp->capacity = hp->capacity * 2;
		hp->data = (HPDataType *)realloc(hp->data, sizeof(HPDataType)* hp->capacity);
	}
	while (cur)
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])
		{
			Swap(&hp->data[cur], &hp->data[(cur - 1) / 2]);
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap *hp)
{
	Swap(hp->data, hp->data + hp->size - 1);
	hp->size--;
	DownAdjust(hp, 0);
}
HPDataType HeapTop(Heap *hp)
{
	if (hp->size == 0)
	{

		return NULL;
	}
	return hp->data[0];
}
int HeapSize(Heap *hp)
{
	return hp->size;
}
int HeapEmpty(Heap *hp)
{
	return hp->size = 0;
}
void HeapSort(Heap *hp)
{
	int tmp = hp->size;
	while (hp->size)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}
void HeapPrint(Heap *hp)
{
	int i;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);

		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}
