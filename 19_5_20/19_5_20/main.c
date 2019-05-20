#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//qsort的使用
int CmpInt(const void *xp, const void *yp)
{
	int *x = (int *)xp;
	int *y = (int *)yp;
	if (*x > *y)
	{
		return 1;
	}
	else if (*x<*y)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void Show(int arr[], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	double d[] = { 1.00, 5.01, 4.02, 3.02, 52.01 };
	int arr[] = { 1, 26, 3, 4, 5, 14, 4, 15, 8 };
	int num = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, num, sizeof(int), CmpInt);
	Show(arr, num);
	system("pause");
	return 0;

}



//利用冒泡排序，模拟实现qsort

void Swap(char *x, char *y, int size)//按字节交换
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < size; i++)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
		x++;
		y++;

	}
}
int Cmp(const void *xp, const void *yp)
{
	int *x = (int *)xp;
	int *y = (int *)yp;
	if (*x > *y)
	{
		return 1;
	}
	else if (*x<*y)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void Show(int arr[], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
}
void My_Qsort(void *arr, int num, int size, \
	int(*Cmp)(const void *, const void *))
{
	assert(arr);
	assert(Cmp);
	char *start = (char *)arr;
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		int flag = 0;//定义、flag，判断原序列是否有序
		for (j = 0; j < num - 1 - i; j++)
		{
			if (Cmp(start + j*size, start + (j + 1)*size) > 0)
			{
				flag = 1;
				Swap(start + j*size, start + (j + 1)*size, size);
			}

		}
		if (!flag)//如果原序列有序，直接break跳出循环
		{
			break;
		}
	}

}


int main()
{
	int arr[] = { 1, 5, 614, 23, 4765, 14, 142478, 122, 8895, 77 };
	int num = sizeof(arr) / sizeof(arr[0]);
	My_Qsort(arr, num, sizeof(int), Cmp);
	Show(arr, num);
	system("pause");
	return 0;
}