#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	char str[] = "abcd";
	char str2[] = { 'a', 'b', 'c', 'd' };
	int a = sizeof(str);
	int b = sizeof(str2);
	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));
	return 0;
}*/
/*int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default: s += 4;
		case 1: s += 1;
		case 2: s += 2;
		case 3: s += 3;
		}
	}
	printf("%d\n", s);
	return 0;
}*/
/*int main()
{
	char *pcColor = "blue1";
	char acColor[] = "blue1";
	printf("%d\n", strlen(pcColor));
	printf("%d\n", strlen(acColor));
	printf("%d\n", sizeof(pcColor));
	printf("%d\n", sizeof(acColor));
	return 0;

}*/
/*int main()
{
	unsigned long ulA = 0x11000000; //ulA���ڴ�����С�˴洢����Ϊ 0000 0011
	printf("%x\n", *(unsigned char *)&ulA);//&ulA�ǵ�һλ�ĵ�ַ
	return 0;
}*/
//�㷨�⣺��д������������Ԫ�س��ִ����������鳤��һ�������
//����һ�����ŷ�  ���������ִ��ڣ���ô�����������м�λ�õ�Ԫ��һ�����������
void Compare(int *a, int *b)
{
	return *a > *b;
}
int Search(int *arr, int num, int size)
{
	int count = 0;
	int i = 0;
	qsort(arr, num, size, Compare);
	for (i = 0; i < num ; i++)
	{
		if (arr[i] == arr[num / 2])
		{
			count++;
		}
	}
	if (count > num / 2)
	{
		return arr[num / 2];
	}
	return -1;
}
//�����������޷�  ����data time�ֱ𱣴��һ������Ԫ�غʹ���������ǰ����Ԫ������һ��Ԫ����ͬ��time++��\
��ͬ��time--����time = 0����data������һ��Ԫ��,����time��1�����һ�ν�time��1��Ԫ�ؾ���Ҫ�ҵ�Ԫ�ء�
int Sear(int *arr, int num)
{
	int i = 0;
	int data = 0;
	int time = 0;
	if (arr == NULL || num <= 0)
	{
		return -1;
	}
	data = arr[0];
	for (i = 0; i < num; i++)
	{
		if (time == 0)
		{
			data = arr[i];
			time = 1;
		}
		else if (data == arr[i])
		{
			time++;
		}
		else
		{
			time--;
		}
	}
	return data;
}
int main()
{
	int arr[] = { 2, 24, 5, 6, 2, 2,2,2,2, 4, 2, 6, };
	int num = sizeof(arr) / sizeof(arr[0]);
	int size = sizeof(int);
	//printf("%d\n", Search(arr, num,size));
	printf("%d\n", Sear(arr, num, size));
	return 0;
}