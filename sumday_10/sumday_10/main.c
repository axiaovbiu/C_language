#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s", p++);
		i++;
	}
	return 0;
}*/
/*int main()
{
	int x[] = { 1, 2, 3, 4, 5, 6 }, *p = x;
	p += 2; *p++;
	return 0;
}*/
/*char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	printf("%s\n", myString());
	return 0;
}*/
/*int main()
{
	int i = 1;
	printf("%d,%d\n", sizeof(i++), i);
	return 0;
}*/
/*int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	return 0;
}*/
//算法题：在字符串中找出第一个只出现一次得字符串。

  char FirstNotRepeatingChar(char* pString)
 {
	     //输入不合法
		     if (!pString)
		         return 0;
	
		     //创建一个哈希表，并初始化
	     int hashTable[256];
	     for (int i = 0; i < 256; i++)
		         hashTable[i] = 0;
	
		     //确定字符串中每个字符出现的次数
		     char* pHashKey = pString;
	     while (*(pHashKey) != '\0')
		         hashTable[*(pHashKey++)]++;
	
		     //找到字符串中只出现一次的那个字符
		     pHashKey = pString;
	     while (*pHashKey != '\0')
		     {
		         if (hashTable[*pHashKey] == 1)
			             return *pHashKey;
		        pHashKey++;
		     }
	
		     //如果这个字符串为空，或者字符串中的每个字符都至少出现两次
		     return 0;
	 }

 int main(void)
 {
	     char str[1000];
	     printf("请输入字符串：");
	     gets(str);
	     if (FirstNotRepeatingChar(str) == 0)
		         printf("输入字符串中没有找到第一个只出现一次的字符！\n");
	     else
		         printf("输入字符串中第一个只出现一次的字符为：%c\n", FirstNotRepeatingChar(str));
	     return 0;
}