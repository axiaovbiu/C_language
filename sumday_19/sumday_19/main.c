#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*int main()
{
	int x = 4;
	 x += x *= x + x;// 8 * 4 + 8 * 4 = 64
	return 0;
}*/
//算法题：字符串压缩。输入字符串只包含a-z字母以及结束标志，请编写函数实现对连续出现的相同字符进行压缩，
void compression(char str[], int len){
	int count = 1;//记录重复个数
	int i;
	for (i = 0; i < len; i++)
	{
		if (str[i] == str[i+1])
		{
			count++;
		}
		else
		{
			if (count == 1)
			{
				printf("%c", str[i]);
			}
			else
			{
				printf("%d%c", count, str[i]);
			}
			count = 1;//重置
		}

	}
}
int main()
{
	char str[99] = "xxxyyyyz";
	int len = strlen(str);
	compression(str, len);

	return 0;
}
