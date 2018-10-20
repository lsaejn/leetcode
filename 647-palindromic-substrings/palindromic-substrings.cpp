//
// Given a string, your task is to count how many palindromic substrings in this string.
//
//
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters. 
//
//
// Example 1:
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//
// Example 2:
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//
// Note:
//
// The input string length won't exceed 1000.
//
//


class Solution {
public:
    //统计回文个数
    //0->0,a->0,a,b,ab->0,a,b,ab,c,ac,bc,abc
    //abcabccbacba
    int countSubstrings(string s) 
    {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        //从前从后遍历都一样bab
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                //aba或者a***a,左边的a是当前元素。需要直到***是不是回文
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) 
                    ++res;
            }
        }
        return res;
    }

};
