
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A {
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b; b.fun(10);
};
int main()
{
	Test();
	return 0;
}

#endif


#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string delspace(string st)//实现删除字符串中多余空格的函数
{
	if (st[0] == ' ')//实现连续首字符空格的删除
	{
		int i;
		for (i = 1; st[i] == ' '; i++);
		st.replace(0, i, "");
	}
	for (int j = 1, i = 1; st[i] != '\0';)//实现字符间和末尾多余空格的删除
	{
		while (st[i] != ' '&&st[i] != '\0') i++;//寻找第一个空格位置
		if (st[i] == '\0') break;//寻找到字符串结尾就跳出循环
		for (j = 1; st[i + j] == ' '; j++);//统计空格数量
		if (st[i + j] == '\0' || !(st[i + j] >= 65 && st[i + j] <= 90 || st[i + j] >= 97 && st[i + j] <= 122) || !(st[i - 1] >= 65 && st[i - 1] <= 90 || st[i - 1] >= 97 && st[i - 1] <= 122)) st.replace(i, j, "");//非字母字符前后有空格完全删除，末尾连续空格将其删除
		else st.replace(i, j, " ");//字符间保留一个空格
		while (st[i] == ' ') i++;//寻找下一个非空格字符
	}
	return st;
}
int main()
{
	string st;
	getline(cin, st);
	int word = 0;
	int count = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == ' ')
		 word = 0; 
		else if (word == 0)
		{
			word = 1;
			count++;
		}
	cout << delspace(st) << endl;
	cout << count;
	return 0;
}