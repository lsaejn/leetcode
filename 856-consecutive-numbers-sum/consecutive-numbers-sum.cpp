// Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?
//
// Example 1:
//
//
// Input: 5
// Output: 2
// Explanation: 5 = 5 = 2 + 3
//
// Example 2:
//
//
// Input: 9
// Output: 3
// Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
//
// Example 3:
//
//
// Input: 15
// Output: 4
// Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
//
// Note: 1 <= N <= 10 ^ 9." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //本质上是看能能被整除。
    //
    //比如能表示成x>0和数组的组合
    //1个数,x+1
    //2个数，那就是x+1,x+2;
    //3个数,那就是x+1,x+2,x+3,
    //4个数，x+1,x+2,x+3,x+4即4x+10
    //5个数5x+15,
    //6个数,6x+
    int consecutiveNumbersSum(int N) 
    {
        int count = 0;//必定可以表示成自己
        int sum = 0;
        for (int i = 1; i <= N; ++i)
        {
            sum += i;
            if (sum>N) break;
            if ((N - sum) % i == 0)
                count++;
        }
        return count;
    }
};
