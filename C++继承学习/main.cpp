
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
string delspace(string st)//ʵ��ɾ���ַ����ж���ո�ĺ���
{
	if (st[0] == ' ')//ʵ���������ַ��ո��ɾ��
	{
		int i;
		for (i = 1; st[i] == ' '; i++);
		st.replace(0, i, "");
	}
	for (int j = 1, i = 1; st[i] != '\0';)//ʵ���ַ����ĩβ����ո��ɾ��
	{
		while (st[i] != ' '&&st[i] != '\0') i++;//Ѱ�ҵ�һ���ո�λ��
		if (st[i] == '\0') break;//Ѱ�ҵ��ַ�����β������ѭ��
		for (j = 1; st[i + j] == ' '; j++);//ͳ�ƿո�����
		if (st[i + j] == '\0' || !(st[i + j] >= 65 && st[i + j] <= 90 || st[i + j] >= 97 && st[i + j] <= 122) || !(st[i - 1] >= 65 && st[i - 1] <= 90 || st[i - 1] >= 97 && st[i - 1] <= 122)) st.replace(i, j, "");//����ĸ�ַ�ǰ���пո���ȫɾ����ĩβ�����ո���ɾ��
		else st.replace(i, j, " ");//�ַ��䱣��һ���ո�
		while (st[i] == ' ') i++;//Ѱ����һ���ǿո��ַ�
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