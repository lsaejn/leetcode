// Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.
//
// Example 1:
//
// Input: 5
// Output: 5
// Explanation: 
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
//
//
//
// Note:
// 1 <= n <= 109
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
    k = 5, the range is 00000-11111，分为00000-01111和10000-11111
    第一个其实是k=4的结果。而第二个，我们排除11开头的，所以是10000-10111,这是k=3
    所以推出满1的情况下满足斐波那契。
    现在的问题是通常不满足，比如10010110,
    我们先搞定右边的00000000-01111111，显然它是f(7)
    然后是10000000-10001111 f(4) 我们将它分成了10010000-10010110和10000000-10001111
    然后是10010000-10010011 f(2)
    然后是10010100-10010101 f(1)
second '1' at 4 digits to the right, add range 10000000-10001111, f(4);
third '1' at 2 digits to the right, add range 10010000-10010011, f(2);
fourth '1' at 1 digits to the right, add range 10010100-10010101, f(1);
最后加上1，是num本身
    */
    int findIntegers(int num)
    {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];//首先你得推出这个公式，比如000-111一共是5个。
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) 
        {
            if (num&(1<<k))//注意只能移30位，第32是符号，移30到次高位，开始比较。移动30位，其实最高位是31.第一位是1则用来分析。
            {
                ans += f[k];
                if (pre_bit) //找到最高位即可
                    return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};
