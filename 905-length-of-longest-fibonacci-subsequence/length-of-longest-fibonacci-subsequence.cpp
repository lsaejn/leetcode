// A sequence X_1, X_2, ..., X_n is fibonacci-like if:
//
//
// 	n >= 3
// 	X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
//
//
// Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.
//
// (Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)
//
//  
//
//
//
//
// Example 1:
//
//
// Input: [1,2,3,4,5,6,7,8]
// Output: 5
// Explanation:
// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
//
//
// Example 2:
//
//
// Input: [1,3,7,11,12,14,18]
// Output: 3
// Explanation:
// The longest subsequence that is fibonacci-like:
// [1,11,12], [3,11,14] or [7,11,18].
//
//
//  
//
// Note:
//
//
// 	3 <= A.length <= 1000
// 	1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
// 	(The time limit has been reduced by 50% for submissions in Java, C, and C++.)
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) 
    {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j)
        {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};
