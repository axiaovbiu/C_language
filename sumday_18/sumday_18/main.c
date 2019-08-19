#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	int i = 6;
	if (i <= 6)
		printf("hello\n");
	else
		printf("bye-bye\n");
	return 0;
}*/
/*int main()
{
	char ch = -1;
	printf("%d\n", ch);
	return 0;
}*/
/*int main()
{
	int i, x, y;
	i = x = y = 0;
	do{
		++i;
		if (i % 2)
			x += i;
		i++;
		y += i++;
	} while (i <= 7);
	printf("%d %d %d\n", i, x, y);
	return 0;
}*/
//算法题：如何判断一个数n是否是2的k次方，不用求2的k次方，只需要判断。
int fun(int n)
{
	if (n < 1)
	{
		return 0;
	}
	int m = n&(n - 1);
	return m == 0;
}
int main()
{
	int n = 6;
	if (fun(n))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}