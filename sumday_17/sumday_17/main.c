#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*int main()
{
	unsigned long pulArrary[] = { 6, 7, 8, 9, 10 };
	unsigned long *pulPtr = pulArrary;
	*(pulPtr + 2) += 2;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 2));
	return 0;
}*/
/*int main()
{
	char *szStr = "abcd";
	szStr += 2;
	printf("%lu\n", szStr);
	return 0;
}*/
/*int main()
{
	int i;
	char acNew[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (i = 0; i < 10; i++)
	{
		acNew[i] = '0';
	}
	printf("%d\n", strlen(acNew));
	return 0;
}*/
/*void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}
void main()
{
	int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	foo(a);
	printf("%d", a[2][1]);
	system("pause");
}*/
/*int main()
{
	int x = 0, y = 0, z = 0;
	z = (x == 1) && (y = 2);
	printf("%d", y);
	return 0;
}*/
//算法题：求一个有序数组中的两个元素相加为k的数字，返回这两个元素的下标.
int *Search(int arr[], int k,int len)
{
	int i = 0;
	int left;
	int right;
	int a[2] = { 0 };
	for (i = 0; i < len; i++)
	{
		if (arr[i] > k)
		{
			break;
		}
	}
	right = i - 1;
	left = 0;
	while (left <= right)
	{
		if ((arr[left] + arr[right]) < k)
		{
			left++;
		}
		else if ((arr[left] + arr[right]) > k)
		{
			right--;
		}
		else
		{
			printf("%d %d\n", left, right);
			break;
		}
	}
	return NULL;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Search(arr,5,len);
	return 0;
}