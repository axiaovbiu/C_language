#define _CRT_SECURE_NO_WARNINGS 1
/*int main()
{
	int i = 0;
	while (i < 10)
	{
		if (i < 1)continue;
		if (i == 5)break;
		i++;
	}
	return 0;
}*/

//算法题:要求写一个函数，将字符串中的空格替换为%20
void StrReplace(char *str, int len)
{
	int i = 0;
	int newlen;
	int p1 = 0;
	int p2 = 0;
	int count = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	newlen = len + count * 2;
	p1 = len, p2 = newlen;
	while (p1!=p2)
	{
		str[p2] = str[p1];
		if (str[p1] == ' ')
		{
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else
		{
			p2--;
		}
		p1--;
	}
}
int main()
{
	char str[] ="abc defgx yz";
	int len = sizeof(str) / sizeof(str[0]);
	StrReplace(str, len);
	puts(str);
	return 0;
}