#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main()
{
	struct tagTest1
	{
		short a;
		char b;
		long c;
		long d;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char a;
		long d;
	};
	enum ENUM_A
	{
		x1,
		y1,
		z1 = 5,
		A1,
		B1
	};
	enum ENUM_A A= y1;
	enum ENUM_A B = B1;
	struct tagTest1 s1;
	struct tagTest2 s2;
	struct tagTest3 s3;
	printf("%d %d %d \n", sizeof(s1), sizeof(s2), sizeof(s3));
	return 0;
}*/
/*int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k = fun(j,m);
	printf("%d\n", k);
	k = fun(j, m);
	printf("%d\n", k);
	return 0;
}*/
//�㷨�⣺дһ����������unsigned int �ͱ���x���ڴ��ж�����1�ĸ���
//����һ�����ƶ����жϱ���λ�Ƿ�1
int Function(unsigned int x)
{
	int i;
	int count = 0;
	for (i = 0; i  < 32; i++)
	{
		if (x & 1)
		{
			count++;
		}
		x >>= 1;
	}
	return count;
}
//����������x&��x-1����ѭ��ִ�еĴ�����������1�ĸ���
int Function2(unsigned int x)
{
	int count = 0;
	while (x &= x-1)
	{
		count++;
	}
	return count;
}
int main()
{
	int result = Function(526);
	int result2 = Function(589);
	printf("%d\n", result2);
	return 0;
}