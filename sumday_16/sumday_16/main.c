#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&arr + 1);
	printf("%d %d\n", (*arr + 1), *(ptr - 1));
	return 0;
}*/
/*int main()
{
	unsigned short sht = 0;
	sht--;
	printf("%d", sht);
	return 0;
}*/
//算法题：模拟实现函数pow（x，y），即实现运算x^y（x的y次方），这里x，y都为整数 
double MyPow(double x, int y)
{
	double s = x;
	if (x == 0)
	{
		return 0;
	}
	if (x == 1 || y == 0)
	{
		return 1;
	}
	if (y < 0)
	{
		while (y+1)
		{
			x *= s;
			y++;
		}
		return (1/x);
	}
	else
	{
		while (y-1)
		{
			x *= s;
			y--;
		}
		return  x;
	}
}
int main()
{
	printf("%f\n", MyPow(-2, -2));
	return 0;
}