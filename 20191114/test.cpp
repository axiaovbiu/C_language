/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 * n<=39*/

class Solution {
    public:
        int Fibonacci(int n) {
            int first = 0;
            int second = 1;
            int third = 0;
            if(n <= 1)
                return n;
            for(int i = 2; i <= n; ++i)
            {
                third = first + second;
                first = second;
                second = third;

            }
            return third;
        }

};


/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。*/


class Solution{
    public:
        //因为只有跳1级和2级台阶两种情况，所以，跳到n阶台阶可以从n-1跳一阶，或从n-2跳
        //两阶，跳到n-1阶台阶又有两种方法，依次类推跳到n阶jumpFloor(n) = jumpFloor(n - 1)+jumpFloor(n - 2)
        int jumpFloor(int n)
        {
            if(n == 1)
                return 1;
            if(n == 2)
                return 2;
            return jumpFloor(n - 1) + jumpFloor(n - 2);
        }
};




/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */


class Solution{
    public:
        //与普通青蛙跳台阶问题不同，当为n阶台阶，青蛙就可以跳n阶
        //当n=1,j(1) = 1
        //当n=2,j(2)=j(2-1)+j(2-2)   //j(2-2)表示一次2跳阶,j(2-1)表示一次跳1阶，问题回归到j(1)
        //当n=3,j(3) = j(3-1)+j(3-2)+j(3-3) //j(3-3)表示一次跳3阶,j(3-2)表示一次跳2阶，问题回归到j(1),
        //j(3-1)表示一次跳1阶，问题回归到j(2),j(2)又分为j(2-1)和j(2-2)
        //....
        //j(n)=j(n-1)+j(n-2)+j(n-3)+....+j(2)+j(1)
        //j(n-1)=j(n-2)+j(n-3)+j(n-4)+...+j(2)+j(1)
        //化简可得:j(n)=2*j(n-1)
        jumpFloorII(int n)
        {
            if(n == 1)
                return 1;
            return 2*(jumpFloorII(n - 1));
        }
};




/*
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * */

class Solution {
    public:
        //实质还是Fibonacci数列问题
        int rectCover(int number) {
            int first = 1;
            int second = 2;
            int third;
            if(number <= 2)
                return number;
            for(int i = 3; i <= number; ++i)
            {
                third = first + second;
                first = second;
                second = third;

            }
            return third;

        }

};
