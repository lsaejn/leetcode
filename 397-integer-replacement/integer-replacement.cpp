//
// Given a positive integer n and you can do operations as follow:
//
//
//
//
// If n is even, replace n with n/2.
// If n is odd, you can replace n with either n + 1 or n - 1.
//
//
//
//
// What is the minimum number of replacements needed for n to become 1?
//
//
//
//
// Example 1:
//
// Input:
// 8
//
// Output:
// 3
//
// Explanation:
// 8 -> 4 -> 2 -> 1
//
//
//
// Example 2:
//
// Input:
// 7
//
// Output:
// 4
//
// Explanation:
// 7 -> 8 -> 4 -> 2 -> 1
// or
// 7 -> 6 -> 3 -> 2 -> 1
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //第一感觉是动态规划，但是n的状态取决于n+1,这就突然很尴尬。但是仔细一看，其实不是取决于n+1,而是却决于n+1/2
    //然后豁然开朗
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) 
            return 1 + integerReplacement(n / 2);
        else {
            long long t = n;
            return 2 + min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }
    }
};
