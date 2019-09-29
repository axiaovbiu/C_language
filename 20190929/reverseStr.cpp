#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
public: 
  string reverseStr(string s, int k)
  {
    string::iterator it = s.begin();
    while(it < s.end() && (it + k) <= s.end())
    {
      reverse(it,it + k);
      it = it + 2 * k;
    }
    if((it + k) > s.end())
    {
      reverse(it,s.end());
    }
   return s;
  }
};
int main()
{
  string s("abcd");
  Solution test;
  string b = test.reverseStr(s,3);
  cout << b << endl;
  return 0;
}
