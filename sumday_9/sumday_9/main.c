#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*void func(char str[2])
{
	int m = sizeof(str);
	int n = strlen(str);
	printf("%d\n", m);
	printf("%d\n", n);
}
int main()
{
	char str[] = "hello";
	func(str);
	return 0;
}*/
/*int main()
{
	int a, x;
	for (a = 0, x = 0; a <= 1 && !x++; a++)
	{
		a++;
	}
	printf("%d %d", a, x);
	return 0;
}*/
/*int main()
{
	int a[5] = {1,2,3,4,5};
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);
	printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);
	return 0;
}*/
//算法题：输入一个整型数组，数组里面有正数也有负数，数组中一个或连续多个整数组成一个子数组，求所有子数组的和的最大值。要求时间复杂度为O（n）
int MaxSum(int *arr, int len)
{
	int i = 0;
	int sum = 0;
	int maxsum = 0;
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		if (sum > 0)
		{
			if (sum > maxsum)
			{
				maxsum = sum;
			}
		}
		else
		{
			sum = 0;
		}
	}
	return maxsum;
}
int main()
{
	int arr[] = { -2, 7, 3, -2, 10, -40, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", MaxSum(arr, len));
	return 0;
}
