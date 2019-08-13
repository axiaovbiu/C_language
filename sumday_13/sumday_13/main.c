#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*int main()
{
	int a[] = { 0, 2, 4, 6, 8, 10 };
	int *p = a;
	*p++;
	//(*p)++;
	//*++p;
	return 0;
}*/
/*int main()
{
	int c[] = { 1, 3, 5 };
	int *k = c + 1;
	printf("%d\n", *++k);
	return 0;
}*/
/*#include<stdio.h>
#define sum(a,b,c) a+b+c
int main()
{
	int i = 3;
	int j = 2;
	printf("%d\n", i *sum(i, (i + j), j));
	return 0;
}*/
/*int f(int n)
{
	static int i = 1;
	if(n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	printf("%d\n", f(1));
	return 0;
}*/
/*int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	printf("%d\n", (func()));
	return 0;
}*/
//算法题：输入两个字符串，从第一个字符串中删除第二个字符串中所有的字符。
void StrDele(char str[], char del_str[])
{
	int i = 0;
	int hash[256];
	char *pfast = str;
	char *pslow = str;
	int del_len = strlen(del_str);
	for (i = 0; i < 256; i++)
	{
		hash[i] = 0;
	}
	for (i = 0; i < del_len; i++)
	{
		hash[del_str[i]] = 1;
	}
	while (*pfast)
	{
		if (hash[*pfast] == 0)
		{
			*pslow = *pfast;
			pslow++;
		}
		pfast++;
	}
	*pslow = '\0';
}
int main()
{
	char str[] = "abcdf";
	char del_str[] = "bdc";
	StrDele(str, del_str);
	printf("%s\n", str);
	return 0;
}