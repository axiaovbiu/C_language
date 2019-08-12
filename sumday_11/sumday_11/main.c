#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int fun(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return(p - s);
}
int main()
{
	printf("%d\n", fun("goodbye!"));
	return 0;
}*/
/*int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);
	return 0;
}*/
int main()
{
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	printf("%d,%d", i, *j);
	return 0;
}