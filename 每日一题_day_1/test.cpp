#if 0
/*
 * 牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一
 * 共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
 * 例如:
 * 一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
 * 一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
 * 一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
 * 为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
 * 如样例所示:
 * 如果牛牛把6个队员划分到两个队伍
 * 如果方案为:
 * team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
 * 而如果方案为:
 * team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
 * 没有比总和为10更大的方案,所以输出10.
 * 输入描述：
 * 输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
 * 第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
 * 输出描述：
 * 输出一个整数表示所有队伍的水平值总和最大值.
 * 示例1:
 * 输入
 * 2
 * 5 2 8 5 1 5
 * 输出
 * 10*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    vector<int> v;
    while(cin>>n)//循环输入
    {
        long long sum = 0;
        v.resize(3*n);
        for(size_t i = 0; i < v.size(); ++i)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());//将数组排序，最小值会放在左边，舍去最小值，将剩下的数字两个分为一组，取次大值
        for(int i = n; i < 3*n-2; i += 2)
        {
            sum += v[i];
        }
        
        cout<<sum<<endl;
    }
    return 0;
}



/*
 * 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are
 * students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
 * 输入描述：
 * 每个测试输入包含2个字符串
 * 输出描述：
 * 输出删除后的字符串
 * 示例1:
 * 输入
 * They are students.
 * aeiou
 * 输出
 * Thy r stdnts.*/
#endif


#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2,res;
    getline(cin,str1);//cin输入字符串，遇到空格就会结束，尽量使用getline()
    getline(cin,str2);
    int hashtable[256] = {0};//使用哈希思想，将str2中的字符串记录在哈希表中
    for(size_t i = 0; i < str2.size(); ++i)
    {
        hashtable[str2[i]]++;
    }
    for(size_t i = 0; i < str1.size(); ++i)
    {
        if(hashtable[str1[i]] == 0)
        {
            res +=str1[i];
        }
    }
    cout << res << endl;
    return 0;
}
#endif


#if 0
/*
 * 牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一
 * 个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数
 * 组分为几段排序子序列.
 * 如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出
 * 2
 * 输入描述：
 * 输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
 * 第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。
 * 输出描述：
 * 输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
 * 示例1:
 * 输入
 * 6
 * 1 2 3 2 2 1
 * 输出
 * 2*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n + 1);//因为是v[i]和v[i + 1]比较，所以空间加一，防止越界
    //给多出来的一个空间赋值为0
    //1>当到v[n - 1]时的最后一组序列为非递减，因为前面的输入大于0(题目告知)，i == n-1时，
    //  内部循环结束count++，i++外部循环结束
    //2>当到v[n - 1]时的最后一组序列为非递增，因为前面的输入大于0(题目告知)，i == n-1时,
    //  i++内部循环结束，count++,i++外部循环结束
    //3>当到v[n - 1]时的最后一组序列为单个元素，添加0后，让其变成非递增序列，count++
    v[n] = 0;
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    int j = 0;
    int count = 0;
    while(j < n)
    {
        //非递减序列
        if(v[j] < v[j + 1])
        {
            while(j < n && v[j] <= v[j + 1])
            {
                j++;
            }
            count++;
            j++;
        }
        else if(v[j] == v[j + 1])
        {
            j++;
        }
        else//非递增序列
        {
            while(j < n && v[j] >= v[j + 1])
            {
                j++;
            }
            count++;
            j++;
        }
    }
    cout << count << endl;
    return 0;
}
#endif




/*
 * 将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
 * 输入描述：
 * 每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
 * 输出描述：
 * 依次输出倒置之后的字符串,以空格分割
 * 示例1:
 * 输入
 * I like beijing.
 * 输出
 * beijing. like I
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    reverse(s.begin(),s.end());//现将字符串整体逆置
    auto start = s.begin();
    while(start != s.end())//将单个字符逆置
    {
        auto end = start;
        while(end != s.end() && *end != ' ')
        {
            end++;
        }
        reverse(start,end);
        if(end != s.end())
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    cout << s << endl;
    return 0;
}
