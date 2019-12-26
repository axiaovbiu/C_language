#include<iostream>
#include<string>
using namespace std;
string{
public:
  string(char *str = "")
  {
    if(str == nullptr)
    {
      str = "";
    }
    _str = new char[strlen(str + 1)];
    strcpy(_str,str);
  }
  string(const string &s)
    :_str new char[strlen(str) + 1];
  {
    strcpy(_str,str);
  }
  string &operator(const string s)
  {
    if(this != &s)
    {
      char *temp = new char[strlen(s._str) + 1];
      strcpy(temp,s._str);
      delete[] _str;
      _str = temp;
    }
  }
  ~string()
  {
    if(_str)
    {
      delete[] _str;
    }
    _str = nullptr;
  }
private:
    char *_str;
};
