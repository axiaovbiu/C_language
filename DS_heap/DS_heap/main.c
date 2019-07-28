#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))
int main()
{
	int a[] = { 1, 2, 3, 5, 4, 6, 7 };
	Heap hp;
	HeapInit(&hp, a, ARRSIZE(a));
	HeapPop(&hp);
	HeapPush(&hp, 5);
	HeapPrint(&hp);
	HeapSort(&hp);
	return 0;
}