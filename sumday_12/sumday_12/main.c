#define _CRT_SECURE_NO_WARNINGS 1
/*int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
int main()
{
	int result = f(2, 4);
	printf("%d\n", result);
	return 0;
}*/
/*int fun(int x, int y, int *c, int *d)
{
	*c = x + y;
	*d = x - y;
}
int main()
{
	int a = 4, b = 3, c = 0, d = 0;
	fun(a, b, &c, &d);
	printf("%d %d\n", c, d);
	return 0;
}*/
//�㷨�⣺һ����������������������⣬�������ֶ����������Σ���д�����ҳ�������ֻ����һ�ε����֡�
void Fun(int arr[], int len)
{
	int i = 0;
	int tmp = 0;
	int j = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)//�Ƚ��������������Ϊֻ������ֻ����һ�εĲ�ͬ�����֣����Խ��tmp�ض���Ϊ0
	{
		tmp ^= arr[i];
	}
	for (j = tmp; j; j /= 2)//�ҳ�tmp�������е�һ�γ���1��λ��pos��pos������������ֻ����-++6һ�εĲ�ͬ����
	{
		if (j % 2 == 1)
		{
			break;
		}
		pos++;
	}
	for (i = 0; i < len; i++)//��������pos��Ϊ1�����ַ�Ϊһ�飬�����Ϊһ�飬�ֱ����
	{
		if ((arr[i] >> pos) & 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d %d\n",x ,y);
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Fun(arr, len);
	return 0;
}
