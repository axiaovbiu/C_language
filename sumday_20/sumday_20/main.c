#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h.>
/*int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}
int main()
{
	printf("%d\n", fun(2019));
	return 0;
}*/
/*int func(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;//逗号表达式，相当于a = b++;所以a = 0；
	return (a);
}
int main()
{
	int a = 2, i,k;
	for (i = 0; i < 0; i++)
	{
		k = func(a++);
	}
	printf("%d\n", k);
	return 0;
}*/
/*int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1: s += 1;
		case 2: s += 2;
		case 3: s += 3;
		}
	}
	printf("%d\n", s);
	return 0;
}*/
//算法题： 编写写代码完成如下功能：删除字符串首尾的空格，中间的连续空格只留一个，原来字符串的顺序不变。
char* del_space(char *str)
{
	int i = -1, j = strlen(str), cur = 0;
	char *fp = NULL;
	char *fp_temp = NULL;
	if (str == NULL)
	{
		return "error";
	}
	//去掉前后空格
	while (str[++i] == ' ')//前++在此处比较好控制好i的值
	{

	}
	while (str[--j] == ' ')
	{

	}
	for (; i <= j; ++i, ++cur)
	{
		str[cur] = str[i];
	}
	str[cur] = '\0';
	fp = fp_temp = str;//fp记录字符串，否则丢失；
	while (*str)
	{
		if (*str != ' ')
		{
			*fp_temp = *str;
			fp_temp++;
		}
		else
		{
			if (*(fp_temp - 1) != ' ')//只取一个空格
			{
				*fp_temp = *str;
				fp_temp++;
			}
		}
		str++;
	}
	*fp_temp = '\0';
	return fp;
}
void main()
{
	char str[] = "    qgsdfg  dfg  dfgd       fgdfg ";

	char *p = del_space(str);
	printf("%s", p);

	system("pause");
}
