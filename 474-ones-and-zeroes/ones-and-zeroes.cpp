// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//
// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
//
//
//
// Note:
//
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
//
//
//
// Example 1:
//
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4
//
// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
//
//
//
// Example 2:
//
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2
//
// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
//
//


class Solution {
public:
    //m个0和n个1最多能形成几个给定的字符串
    //以字符个数
    /*
    建立一个二维的DP数组，其中dp[i][j]表示有i个0和j个1时能组成的最多字符串的个数，而对于当前遍历到的字符串，我们统计出其中0和1的个数为zeros和ones，然后dp[i - zeros][j - ones]表示当前的i和j减去zeros和ones之前能拼成字符串的个数，那么加上当前的zeros和ones就是当前dp[i][j]可以达到的个数，我们跟其原有数值对比取较大值即可，所以递推式如下：

dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    
    */
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)
        {
            int zeros = 0, ones = 0;
            for (char c : str) (c == '0') ? ++zeros : ++ones;
            for (int i = m; i >= zeros; --i) 
                for (int j = n; j >= ones; --j) 
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
        return dp[m][n];  
    }
};
