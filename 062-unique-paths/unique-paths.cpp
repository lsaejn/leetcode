// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
//
//
// Above is a 7 x 3 grid. How many possible unique paths are there?
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
//
//
// Example 2:
//
//
// Input: m = 7, n = 3
// Output: 28
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int uniquePaths(int m, int n) {//每个格子只可能从左边和上边过来。它们都只能从左上角走一步获得，现在多一个分支所以dp[i]=dp[左]+dp[上]
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) 
        {
            for (int j = 1; j < n; ++j) 
            {
                dp[j] += dp[j - 1]; //下=dp[j - 1]左，dp[上]
            }
        }
        return dp[n - 1];
    }
};
