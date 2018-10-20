// We have an array A of non-negative integers.
//
// For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].
//
// Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)
//
//  
//
//
// Example 1:
//
//
// Input: [0]
// Output: 1
// Explanation: 
// There is only one possible result: 0.
//
//
//
// Example 2:
//
//
// Input: [1,1,2]
// Output: 3
// Explanation: 
// The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
// These yield the results 1, 1, 2, 1, 3, 3.
// There are 3 unique values, so the answer is 3.
//
//
//
// Example 3:
//
//
// Input: [1,2,4]
// Output: 6
// Explanation: 
// The possible results are 1, 2, 3, 4, 6, and 7.
//
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 50000
// 	0 <= A[i] <= 10^9
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //[1,1,2]
    //dp超时
    //用vector，超时。。。
    int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            cur = cur2;
            for (int j: cur) res.insert(j);
        }
        return res.size();
    }
};

