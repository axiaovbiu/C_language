#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
//1. ģ��ʵ��string�ද̬�����ַ���
//2. ǳ����
namespace test
{
	//��ͳ��
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
		//������Ĭ�ϵĿ������캯��---ǳ����
		/*string(const string &s)
		: _str(s._str)
		{}*/
		string(const string &s)//�¿��ٿռ䣬������Դ�����Ա������ǳ����
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//������Ĭ�ϵĸ�ֵ���������---�ᵼ��ǳ��������
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
	//�ִ���
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
		string(const string &s)//�������ʼ��Ϊnullptr���ڹ������ʱ����ռ䣬ʡȥ��������Ŀռ��������
			: _str(nullptr)
		{
			string strtemp(s._str);
			swap(_str, strtemp._str);//������Դ����Ϊ��ʼ��Ϊnullptr�����Բ����ͷſռ�
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