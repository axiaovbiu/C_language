#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *My_Strcpy( char *dest, char *src,int n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;//定义*ret保存dest的地址
	while (n && (*dest++ = *src++))//当n为0或*src为'\0',停止拷贝
	{
		n--;
	}
	if (n >0)
	{
		while (--n)
		{
			*dest++ = '\0';
		}
	}
	if (0 == n)
	{
		*dest++ = '\0';
	}
	return ret;
}
int main()
{
	char dest[80] = "as";
	char src[] = "hellow bit";
	printf("%s\n", My_Strcpy(dest, src, 6));
	system("pause");
	return 0;
}
char *My_Strncat(char *dest, const char *src,int n)
{
	assert(dest);
	assert(src);
	char *ret = dest;//定义*ret保存dest的地址
	while (*dest)//利用循环，找到数组dest的'\0'
	{
		dest++;
	}
	while (n && (*dest++ = *src++))//从dest的'\0'开始 ，依次存入src数组的n个元素
	{
		n--;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char dest[80] = "hellow bit";
	char src[] = "hellow word";
	printf("%s\n", My_Strncat(dest, src,2));
	system("pause");
	return 0;
}
int My_Strncmp(const char*str1, const char *str2, int n)
{
	assert(str1);
	assert(str2);
	int ret = 0;//定义整型，保存结果
	while (n && (*str1 == *str2))
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		n--;
		str1++;
		str2++;
		
	}
	return*str1 - *str2;//返回*str1与*str2的差值
}
int main()
{
	char str1[80] = "hellow bit";
	char str2[] = "hellow word";
	printf("%d\n", My_Strncmp(str1,str2,10));//若打印结果=0，则str1=str2，若<0，则str1<str2,若>0,则str1>str2
	system("pause");
	return 0;
}