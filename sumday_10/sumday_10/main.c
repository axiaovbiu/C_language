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
//�㷨�⣺���ַ������ҳ���һ��ֻ����һ�ε��ַ�����

  char FirstNotRepeatingChar(char* pString)
 {
	     //���벻�Ϸ�
		     if (!pString)
		         return 0;
	
		     //����һ����ϣ������ʼ��
	     int hashTable[256];
	     for (int i = 0; i < 256; i++)
		         hashTable[i] = 0;
	
		     //ȷ���ַ�����ÿ���ַ����ֵĴ���
		     char* pHashKey = pString;
	     while (*(pHashKey) != '\0')
		         hashTable[*(pHashKey++)]++;
	
		     //�ҵ��ַ�����ֻ����һ�ε��Ǹ��ַ�
		     pHashKey = pString;
	     while (*pHashKey != '\0')
		     {
		         if (hashTable[*pHashKey] == 1)
			             return *pHashKey;
		        pHashKey++;
		     }
	
		     //�������ַ���Ϊ�գ������ַ����е�ÿ���ַ������ٳ�������
		     return 0;
	 }

 int main(void)
 {
	     char str[1000];
	     printf("�������ַ�����");
	     gets(str);
	     if (FirstNotRepeatingChar(str) == 0)
		         printf("�����ַ�����û���ҵ���һ��ֻ����һ�ε��ַ���\n");
	     else
		         printf("�����ַ����е�һ��ֻ����һ�ε��ַ�Ϊ��%c\n", FirstNotRepeatingChar(str));
	     return 0;
}