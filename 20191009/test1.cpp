#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
  int singleNumber(vector<int> &nums)
  {
    int value = 0;
    for(size_t i = 0; i < nums.size(); ++i)
    {
      value ^= nums[i];
    }
    return value;
  }
};
int main()
{
  Solution a;
  int arr[] = {0,0,2,2,3,5,5};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
  int ret = a.singleNumber(v);
  cout << ret << endl;
}
