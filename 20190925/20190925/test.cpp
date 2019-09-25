#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
class A
{

};
class B
{
	void Func1()
	{}
	void Func2()
	{}
	int a;
	char b;
	double c;
};
class Date
{
public:
	void Display()
	{
		cout << this << endl;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1,d2;
	d1.SetDate(2019, 9, 25);
	d2.SetDate(2019, 9, 26);
	d1.Display();
	d2.Display();

	return 0;
}
#endif
/*��Ŀ����
���һ���ַ���Ϊstr�����ַ�����ǰ�����ⲿ��Ų�������γɵ��ַ�����str����ת�ʡ�����str = ��12345����str����ת���С�12345������45123���ȵȡ����������ַ������ж��Ƿ�Ϊ��ת�ʡ�
�������� :
����������У���һ����������n��m��1 \leq n, m \leq10 ^ 5 ����1��n, m��10
5
�����ֱ��ʾ�����ַ����ĳ��ȡ��ڶ��к͵����и�����һ���ַ�����
������� :
��������ַ�����Ϊ��ת���������YES�������������NO����*/
bool IsRotation(const string &fathstr, const string &sonstr)
{
	string temp = fathstr + fathstr;//���������ӣ�������ж������Ӵ��Ƿ�Ϊ������ת���
	if (temp.find(sonstr) != temp.npos)//����find�����Ӵ�
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main()
{
	int n, m;
	string fathstr, sonstr;
	cin >> n >> m;
	cin >> fathstr;
	cin >> sonstr;
	if (1 == IsRotation(fathstr, sonstr))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
/*
��Ŀ����
���������ַ���str1��str2�����str1��str2�г��ֵ��ַ�������ֵ�һ����ÿ���ַ����ֵĴ���Ҳһ������ôstr1��str2��Ϊ���δʡ����ж�str1��str2�Ƿ�Ϊ���δʡ�
�������� :
�������3�У���һ�а�����������n��m(1 \leq n, m\leq 10 ^ 5)(1��n, m��10
	5
	)�ֱ����str1��str2�ĳ��ȣ��ڶ��к͵�����Ϊ�����ַ������ֱ����str1��str2��
������� :
���str1��str2��Ϊ���δʣ��������true�������������false����*/


bool IsDeformation(string str1, string str2)
{
	char arr[256] = { 0 };//����һ�����������ַ�
	for (auto e : str1)//����str1�е��ַ���ÿ����һ�ξ�++
	{
		arr[e]++;
	}
	for (auto e : str2)//����str2�е��ַ���ÿ����һ�ξ�--
	{
		arr[e]--;
	}
	for (size_t i = 0; i < 256; ++i)//�������������飬�ж������ַ����ֵ����մ����Ƿ�Ϊ0
	{
		if (arr[i] != 0)
		{
			return false;;
		}
	}
	return true;
}
int main()
{
	int n, m;
	string str1, str2;
	cin >> n >> m;
	cin >> str1 >> str2;
	if (IsDeformation(str1,str2))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}