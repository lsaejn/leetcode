// Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
//
//
// 	B.length >= 3
// 	There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
//
//
// (Note that B could be any subarray of A, including the entire array A.)
//
// Given an array A of integers, return the length of the longest mountain. 
//
// Return 0 if there is no mountain.
//
//  
//
// Example 1:
//
//
// Input: [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
//
//
// Example 2:
//
//
// Input: [2,2,2]
// Output: 0
// Explanation: There is no mountain.
//
//
//  
//
// Note:
//
//
// 	0 <= A.length <= 10000
// 	0 <= A[i] <= 10000
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //相当清晰，两个dp
    int longestMountain(vector<int> A) 
    {
        int N = A.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);
        for (int i = N - 2; i >= 0; --i) 
            if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
        for (int i = 0; i < N; ++i) 
        {
            if (i > 0 && A[i] > A[i - 1]) 
                up[i] = up[i - 1] + 1;
            if (up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};
