#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
	return 0;
}*/

//�㷨��:��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά����\
�ж��������Ƿ��и�������ʱ�临�Ӷ�O��row+col��
/*void Search(int arr[][4], int n,int ROW, int COL)
{
	int row = 0;
	int col = COL - 1;
	while ((col >= 0) && (row  <ROW))
	{
		if (arr[row][col] > n)
		{
			col--;
		}
		if (arr[row][col] < n)
		{
			row++;
		}
		if (arr[row][col] == n)
		{
			printf("%d\n", n);
			return;
		}
	}
	return NULL;
}
int main()
{
	int arr[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	Search(arr, 10,4,4);
	return 0;
}*/
/*int main()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	return 0;
}*/

