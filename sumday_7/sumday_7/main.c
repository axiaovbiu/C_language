#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	int x = 0;
	switch (++x)
	{
	case 0: ++x;
	case 1: ++x;
	case 2: ++x;
	}
	return 0;
}*/
//算法题：有一个数组a，编写函数，求数组中前k个最小的数字
void Swap(int *a, int *b)
{
	return *a > *b;
}
void Search(int *a, int num, int size,int k)
{
	int i = 0;
	qsort(a, num, size, Swap);
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int a[] = { 1, 2, 3, 456, 7, 865, 715, 566, 16, 1 };
	int num = sizeof(a)/sizeof(a[0]);
	int size = sizeof(int);
	Search(a, num, size,5);
	return 0;
}