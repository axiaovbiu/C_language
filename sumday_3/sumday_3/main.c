 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	char acHello[] = "hello\0world";
	char acNew[15] = { 0 };
	strcpy(acNew, acHello);
	printf("%s", acNew);
	printf("%d\n", strlen(acNew));
	printf("%d\n", sizeof(acHello));
	return 0;
	
}*/

//算法题：递归与非递归求第n个菲波那切数
/*int Fib(int n)
{
	int first = 1;
	int second = 1;
	int third = 0;
	int i = 0;
	if (n <= 2)
	{
		return 1;
	}
	for (i = 0; i < n - 2; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}*/
int Fib2(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fib2(n - 2) + Fib2(n - 1);
	}
}
int main()
{
	int result = Fib2(10);
	printf("%d", result);
	return 0;
}
