//
// Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.
//
// A subsequence of a string S is obtained by deleting 0 or more characters from S.
//
// A sequence is palindromic if it is equal to the sequence reversed.
//
// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.
//
//
// Example 1:
//
// Input: 
// S = 'bccb'
// Output: 6
// Explanation: 
// The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
// Note that 'bcb' is counted only once, even though it occurs twice.
//
//
//
// Example 2:
//
// Input: 
// S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
// Output: 104860361
// Explanation: 
// There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
//
//
//
// Note:
// The length of S will be in the range [1, 1000].
// Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        vector<vector<int>> chars(26, vector<int>());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            chars[S[i] - 'a'].push_back(i);
        }
        return helper(S, chars, 0, n, memo);
    }
    int helper(string S, vector<vector<int>>& chars, int start, int end, vector<vector<int>>& memo) {
        if (start >= end) return 0;
        if (memo[start][end] > 0) return memo[start][end];
        long res = 0;
        for (int i = 0; i < 26; ++i) {
            if (chars[i].empty()) continue;
            auto new_start = lower_bound(chars[i].begin(), chars[i].end(), start);
            auto new_end = lower_bound(chars[i].begin(), chars[i].end(), end) - 1;
            if (new_start == chars[i].end() || *new_start >= end) continue;
            ++res;
            if (new_start != new_end) ++res;
            res += helper(S, chars, *new_start + 1, *new_end, memo);
        }
        memo[start][end] = res % int(1e9 + 7);
        return memo[start][end];
    }
};
