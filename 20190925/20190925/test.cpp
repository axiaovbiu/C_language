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
/*题目描述
如果一个字符串为str，把字符串的前面任意部分挪到后面形成的字符串交str的旋转词。比如str = “12345”，str的旋转串有“12345”、“45123”等等。给定两个字符串，判断是否为旋转词。
输入描述 :
输出包含三行，第一个两个整数n和m（1 \leq n, m \leq10 ^ 5 ）（1≤n, m≤10
5
），分别表示两个字符串的长度。第二行和第三行各输入一个字符串。
输出描述 :
如果两个字符串互为旋转词请输出“YES”，否则输出“NO”。*/
bool IsRotation(const string &fathstr, const string &sonstr)
{
	string temp = fathstr + fathstr;//将父串叠加，便可以判断所有子串是否为父串旋转情况
	if (temp.find(sonstr) != temp.npos)//利用find查找子串
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
题目描述
给定两个字符串str1和str2，如果str1和str2中出现的字符种类出现的一样且每种字符出现的次数也一样，那么str1和str2互为变形词。请判断str1和str2是否为变形词。
输入描述 :
输入包括3行，第一行包含两个整数n，m(1 \leq n, m\leq 10 ^ 5)(1≤n, m≤10
	5
	)分别代表str1和str2的长度，第二行和第三行为两个字符串，分别代表str1和str2。
输出描述 :
如果str1和str2互为变形词，请输出“true”，否则输出“false”。*/


bool IsDeformation(string str1, string str2)
{
	char arr[256] = { 0 };//定义一数组存放所有字符
	for (auto e : str1)//遍历str1中的字符，每出现一次就++
	{
		arr[e]++;
	}
	for (auto e : str2)//遍历str2中的字符，每出现一次就--
	{
		arr[e]--;
	}
	for (size_t i = 0; i < 256; ++i)//最后遍历整个数组，判断所有字符出现的最终次数是否为0
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