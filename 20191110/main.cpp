//读入一个字符串str，输出字符串str中的连续最长的数字串
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string A;
  cin>>A;
  int pos = 0, flag = 0, mflag = 0;
  int len = A.size();
  string B;
  for(int i = 0; i <= len; ++i)//通过flag记录数字串的大小
  {
    if(A[i] >= '0' && A[i] <= '9')
    {
      flag++;
    }
    else
    {
      if(flag > mflag)//利用mflag记录上个数字串的大小,利用pos记录数字串的入口
      {
        mflag = flag;
        pos = i - flag;
      }
      flag = 0;
    }
  }
  for(int i = 0; i < mflag; ++i)
  {
    B += A[i + pos];//将结果保存在B中
  }
  cout<<B<<endl;
  return 0;

}


//一个数组中有一个数字的次数超过了数组的一半，求出这个字符。如：int a[] = {2,3,2,2,2,2,2,5,4,1,2,3}，求出超过一半的数字是2。
#include<vector>
#include<iostream>
class Soult
{
  int MoreThanHalfNum(vector<int> v)
  {
    if(v.empty())
    return 0;
    sort(v.begin(),v.end());
    int midnum = v[v.size()/2];
    int times = 0;
    for(int i = 0 ; i < v.size(); ++i)
    {
        if(v[i] == midnum)
        {
          ++times;
        }
    }
    return times>v.size()/2?times:0;
  }
};
  
