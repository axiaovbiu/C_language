#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
//1. 模拟实现string类动态管理字符串
//2. 浅拷贝
namespace test
{
	//传统法
	class string
	{
	public:
		string(char *str = "")
		{
			if (str == nullptr)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//编译器默认的拷贝构造函数---浅拷贝
		/*string(const string &s)
		: _str(s._str)
		{}*/
		string(const string &s)//新开辟空间，拷贝资源，可以避免出现浅拷贝
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//编译器默认的赋值运算符重载---会导致浅拷贝问题
		/* string & operator=(const string &s)
		{
			if (this != &s)
			{
				_str = _s._str;
			}
			return *this
		}*/
		string &operator=(const string s)
		{
			if (this != &s)
			{
				char *temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}
			return  *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
			}
			_str = nullptr;
		}
	private:
		char *_str;
	};
}
void TestString()
{
	test::string s1("hello");
	test::string s2(s1);
	test::string s3 = s1;
}
int main()
{
	/*test::string s1("hello");
	test::string s2(nullptr);
	test::string s3(s1);*/
	TestString();
	return 0;
}
#endif
namespace test
{
	//现代法
	class string
	{
	public:
		string(char *str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string &s)//给对象初始化为nullptr，在构造对象时申请空间，省去拷贝构造的空间申请操作
			: _str(nullptr)
		{
			string strtemp(s._str);
			swap(_str, strtemp._str);//交换资源，因为初始化为nullptr，所以不用释放空间
		}
		string &operator=(const string& s)
		{
			if (this != &s)
			{
				string strtemp(s._str);
				swap(_str, strtemp._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char *_str;
	};
}
int main()
{
	return 0;
}