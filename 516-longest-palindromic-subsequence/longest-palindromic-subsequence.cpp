//
// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//
// Example 1:
// Input: 
//
// "bbbab"
//
// Output: 
//
// 4
//
// One possible longest palindromic subsequence is "bbbb".
//
//
// Example 2:
// Input:
//
// "cbbd"
//
// Output:
//
// 2
//
// One possible longest palindromic subsequence is "bb".
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*p[i][j]表示[i,j]区间内的字符串的最长回文子序列
                /  dp[i + 1][j - 1] + 2   ;                    if (s[i] == s[j])
    dp[i][j] =
                \  max(dp[i + 1][j], dp[i][j - 1]) ;       if (s[i] != s[j])
    */
    
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) 
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) 
            {
                if (s[i] == s[j]) 
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else 
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
