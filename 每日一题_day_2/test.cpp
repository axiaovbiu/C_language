/*
 * 读入一个字符串str，输出字符串str中的连续最长的数字串
 * 输入描述:
 * 个测试输入包含1个测试用例，一个字符串str，长度不超过255。
 * 输出描述:
 * 在一行内输出str中里连续最长的数字串。
 * 示例1
 * 输入
 * 复制
 * abcd12345ed125ss123456789
 * 输出
 * 复制
 * 123456789*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,cur,res;
    cin >> str;
    for(size_t i = 0; i < str.size(); ++i)
    {
        //将数字串记录在cur内
        if(str[i] > '0' && str[i] < '9')
        {
            cur += str[i];
        }
        else
        {
            //在res内更新数字串长度
            if(res.size() < cur.size())
            {
                res = cur;
            }
            else
                cur.clear();
        }
    }
    cout << res << endl;
    return 0;
}









/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在�输出0。*
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //方法一：
    int MoreThanHalfNum_solution(vector<int> numbers)
    {
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());//利用sort排序，取中间值mid
        int mid = numbers.size()/2;
        int count = 0;
        for(int i = 0; i < numbers.size(); ++i)//判断mid是否符合题意，即出现的次数超过数组长度的一半
        {
            if(numbers[i] == mid)
                count++;
        }
        return (count > numbers.size()/2) ? mid : 0;
    }
    //方法二：
    int MoreThanHalfNum_solution(vector<int> numbers)
    {
        if(numbers.empty())
        return 0;
        int res = numbers[0];
        int times = 1;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(res == numbers[i])
                times++;
            else if(0 == times)
            {
                res = numbers[i];
                times = 1;
            }
            else
                times--;
        }
        times = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(res == numbers[i])
                times++;
        }
        return (times > numbers.size()/2) ? result : 0;
    }
};

