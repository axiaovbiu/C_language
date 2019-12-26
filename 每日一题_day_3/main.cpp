/*
 * 1. 标题：计算糖果 | 时间限制：1秒 | 内存限制：32768K
 * A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道
 * 以下的信息：
 * A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
 * 现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所
 * 有题设条件。
 * 输入描述：
 * 输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区
 * 间)。
 * 输出描述：
 * 输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在
 * 这样的整数A，B，C，则输出No
 * 示例1:
 * 输入
 * 1 -2 3 4
 * 输出
 * 2 1 3*/
#if 0
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int A = (a+c)/2;
    int C = (d-b)/2;
    int B1 = (c-a)/2;
    int B2 = (b+d)/2;
    if(B1 != B2)
        cout << "NO";
    else
        cout << A << " " << B1 << " " << C;
    return 0;
}
#endif


/*
 * 2. 标题：进制转换 | 时间限制：1秒 | 内存限制：32768K
 * 给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
 * 输入描述：
 * 输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
 * 输出描述：
 * 为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10
 * 用A表示，等等）
 * 示例1:
 * 输入
 * 7 2
 * 输出
 * 111*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s,table = "0123456789ABCDEF";
    int m,n;
    cin>>m>>n;
    bool flag = false;
    if(m < 0)//将负数转正计算，并标记
    {
        m = 0 - m;
        flag = true;
    }
    while(m)//将数字按进制转换成对应的字符，加到s后
    {
        s += table[m%n];
        m /= n;
    }
    if(flag)//若为负数则加-
    s += '-';
    reverse(s.begin(),s.end());//将字符串逆置，就是正常的数字顺序
    cout << s << endl;
    return 0;
}
