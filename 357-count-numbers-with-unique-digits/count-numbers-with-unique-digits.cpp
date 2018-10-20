// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//
//
//     Example:
// Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
//
//
// Credits:Special thanks to @memoryless for adding this problem and creating all test cases." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //0至100内有9个，
    //100至1000内有110~119+101;220~229+202;990~999+909
    //1001至10000,1100~1199+1010~1019,1001/
    //f(k) = 9 * 9 * 8 * ... (9 - k + 2)
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n == 0) return 1;
        int res = 10, cnt = 9;
        for (int i = 2; i <= n; ++i)
        {
            cnt *= (11 - i);//9*9*8*7*...
            res += cnt;
        }
        return res;   
    }
};
