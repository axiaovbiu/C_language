#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*int main()
{
	int x = 4;
	 x += x *= x + x;// 8 * 4 + 8 * 4 = 64
	return 0;
}*/
//�㷨�⣺�ַ���ѹ���������ַ���ֻ����a-z��ĸ�Լ�������־�����д����ʵ�ֶ��������ֵ���ͬ�ַ�����ѹ����
void compression(char str[], int len){
	int count = 1;//��¼�ظ�����
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
			count = 1;//����
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
