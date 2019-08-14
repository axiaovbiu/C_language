#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*int main()
{
int c[] = { 1, 3, 5 };
int *k = c + 1;
printf("%d", *++k);
return 0;
}*/
/*int main()
{
	int a = 2, *p1, **p2;
	p2 = p1;
	p1 = &a;
	a++;
	printf("%d,%d,%d\n", a, *p1, **p2);
	return 0;
}*/
/*int main()
{
	int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
			s += j;
	}
	printf("%d\n", s);
	return 0;
}*/
/*int main()
{
	int arr[] = { 6, 7, 8, 9, 10 };
	int *ptr = arr;
	*(ptr++) += 123;
	printf("%d,%d,%d", *ptr, *(++ptr),arr[0]);
	return 0;
}*/
//算法题：编写一个函数，求一个数是否是回文数。回文数：给定一个数，顺序逆序读，都是这个数。
void  palindrome(int num)
{
	int y = 0;
	int s = num;
	while (s > 0)
	{
		y = y * 10 + s % 10;// 利用s求出num逆置后的每一位，并存放在y中
		s /= 10;
	}
	if (y == num)//让y与num比较，相同就是回文数，不同则不是。
	{
		printf("%d is a palindrome\n",num);
	}
	else
	{
		printf("%d is not a palindrome\n",num);
	}
}
int main()
{
	int a = 121;
	int b = 123;
	palindrome(a);
	palindrome(b);
	return 0;
}