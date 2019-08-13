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
//算法题：一个整型数组除了两个数字外，其他数字都出现了两次，请写程序找出这两个只出现一次的数字。
void Fun(int arr[], int len)
{
	int i = 0;
	int tmp = 0;
	int j = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)//先将数组整体异或，因为只有两个只出现一次的不同的数字，所以结果tmp必定不为0
	{
		tmp ^= arr[i];
	}
	for (j = tmp; j; j /= 2)//找出tmp二进制中第一次出现1的位置pos，pos用来区分两个只出现-++6一次的不同数字
	{
		if (j % 2 == 1)
		{
			break;
		}
		pos++;
	}
	for (i = 0; i < len; i++)//将数组中pos处为1的数字分为一组，其余分为一组，分别异或
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
