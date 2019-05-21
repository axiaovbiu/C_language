#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *My_Strcpy( char *dest, char *src,int n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;//����*ret����dest�ĵ�ַ
	while (n && (*dest++ = *src++))//��nΪ0��*srcΪ'\0',ֹͣ����
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
	char *ret = dest;//����*ret����dest�ĵ�ַ
	while (*dest)//����ѭ�����ҵ�����dest��'\0'
	{
		dest++;
	}
	while (n && (*dest++ = *src++))//��dest��'\0'��ʼ �����δ���src�����n��Ԫ��
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
	int ret = 0;//�������ͣ�������
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
	return*str1 - *str2;//����*str1��*str2�Ĳ�ֵ
}
int main()
{
	char str1[80] = "hellow bit";
	char str2[] = "hellow word";
	printf("%d\n", My_Strncmp(str1,str2,10));//����ӡ���=0����str1=str2����<0����str1<str2,��>0,��str1>str2
	system("pause");
	return 0;
}